from app.controller import *
from app import get_connection
from flask import jsonify
import pymysql as sql
import config
from flask import Flask, render_template, request
import datetime
from app import app

@app.route('/', methods =['GET'])
def route_index():
    controller = Controller(app, get_connection())
    return  controller.index_action()

@app.route('/form', methods =['GET'])
def route_form():
    return render_template("form.html")

@app.route('/lognin', methods =['GET'])
def route_lognin():
    return render_template("log.html")

@app.route('/log', methods =['GET'])
def route_log():
    result=request.args
    username = result['user_name']
    controller = Controller(app, get_connection())
    if controller.check_password(request) == False:
        return render_template("log.html")
    return redirect('/user/' + username + '/profile')

@app.route('/create', methods =['GET'])
def route_create():
    controller = Controller(app, get_connection())
    if controller.exist(request) == True:
        return controller.index_action()
    return controller.register(request)

@app.route('/user/<username>/form-task', methods=['GET'])
def route_form_task(username):
    return render_template("form_task.html", username = username)

@app.route('/user/<username>/create-task', methods=['GET'])
def route_create_task(username):
    controller = UserControler(app, get_connection(), username)
    controller.new_task(request)
    return redirect('/user/' + username + '/profile')

@app.route('/user/<username>/<task_id>/remove-task', methods=['GET'])
def route_remove_task(username, task_id):
    controller = UserControler(app, get_connection(), username)
    return controller.remove_task(request, task_id)

@app.route('/user/<username>/<task_id>/modif', methods=['GET'])
def route_modif(username, task_id):
    controller = UserControler(app, get_connection(), username)
    return controller.modif_task(request, task_id)

@app.route('/user/<username>/<task_id>/form-modif', methods=['GET'])
def route_modif_task(username, task_id):
    controller = UserControler(app, get_connection(), username)
    return controller.info_task(request, task_id)

@app.route('/user/<username>/profile', methods=['GET'])
def route_profile(username):
    controller = UserControler(app, get_connection(), username)
    return controller.view_task(request)