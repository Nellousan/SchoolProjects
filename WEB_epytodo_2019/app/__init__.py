import os
import locale
from flask import Flask
import pymysql as sql
from app.connection import *

app = Flask(__name__)
app.config.from_object('config')

conn = connection(app)
def get_connection():
    return conn.get_connection()

from app import views