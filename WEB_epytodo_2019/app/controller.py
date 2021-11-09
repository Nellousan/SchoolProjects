#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## epytodo
## File description:
## controller
##

from app import app
from app.models import *
from flask import jsonify
import pymysql as sql
import config
from flask import Flask, render_template, request, redirect, url_for
from datetime import date
import hashlib

class Controller(object):

    def __init__(self, app, conn):
        self.app = app
        self.conn = conn
        self.user = User(app, conn)
        self.name = ""

    def index_action(self):
        return render_template("index.html")

    def register(self, request):
        result=request.args
        username = result['user_name']
        password = result['user_password']
        self.user.create_user(username, password)
        self.name = username
        return redirect('/user/' + username + '/profile')
    
    def exist(self, request):
        result=request.args
        username = result['user_name']
        return self.user.find_username(username)
    
    def check_password(self, request):
        result=request.args
        username = result['user_name']
        password = result['user_password']
        self.name = username
        return self.user.find_password(username, password)
    
    def get_name(self):
        print(self.name)
        return self.name
    
class UserControler(object):

    def __init__(self, app, conn, username):
        self.app = app
        self.conn = conn
        self.user = User(app, conn)
        self.task = Task(app, conn)
        self.username = username

    def new_task(self, request):
        result=request.args
        username = self.username
        title = result['task_title']
        if title == "":
            return render_template("form_task.html", username = username)
        begin = result['task_begin']
        end = result['task_end']
        status = result['status']
        self.user.create_task(username, title, begin, end, status)
        return redirect('/user/' + username + '/profile')
    
    def remove_task(self, request, task_id):
        username = self.username
        self.user.remove_task(username, task_id)
        return redirect('/user/' + username + '/profile')
    
    def info_task(self, request, task_id):
        username = self.username
        return self.user.info_task(username, task_id)

    def modif_task(self, request, task_id):
        username = self.username
        result=request.args
        title = result['task_title']
        begin = result['task_begin']
        end = result['task_end']
        status = result['status']
        self.user.modif_task(username, task_id, title, begin, end, status)
        return redirect('/user/' + username + '/profile')

    def view_task(self, request):
        username = self.username
        user_id = self.task.find_user_id(username)
        ret = {}
        task_id = 1
        i = 0
        nb = self.task.get_nb_task(user_id)
        while nb != 0:
            if self.task.task_id_exist(task_id) == True:
                if self.task.find_task_id(user_id, task_id) == True:
                    test = self.task.find_list(task_id)
                    ret[i] = test
                    i = i + 1
                    nb -= 1
            task_id = task_id + 1
        ret[i] = 'end'
        return render_template("profile.html", task = ret, username = username, name = username, title = username)