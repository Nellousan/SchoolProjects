from app import app
from flask import Flask, render_template
from datetime import date
import json

class User(object):
    def __init__(self, app, conn):
        self.conn = conn
        self.app = app
    
    def create_user(self, username, password):
        try:
            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO %s (username, password) VALUES ('%s', '%s')" % ('user', username, password))
            cursor.execute("SELECT * FROM user")
            self.conn.commit()
            cursor.close()
        except Exception as error:
            print(error)

    def find_username(self, username):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT COUNT(1) FROM %s WHERE username = '%s'" % ('user', username))
            exist = cursor.fetchone()[0]
            cursor.close()
            return True if exist == 1 else False
        except Exception as error:
            print(error)
        return True
    
    def find_password(self, username, password):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT password FROM %s WHERE username = '%s'" % ('user', username))
            pwd = cursor.fetchone()[0]
            cursor.close()
            if password == pwd:
                return True
            else:
                return False
        except Exception as error:
            print(error)
        return False
    
    def create_task(self, username, title, begin, end, status):
        try:
            cursor = self.conn.cursor()
            if begin == "":
                begin = date.today()
            if end == "":
                cursor.execute("INSERT INTO %s (title, begin, status) VALUES ('%s', '%s', '%s')" % ('task', title, begin, status))
            else:
                cursor.execute("INSERT INTO %s (title, begin, end, status) VALUES ('%s', '%s', '%s', '%s')" % ('task', title, begin, end, status))
            self.conn.commit()
            task_id = cursor.lastrowid
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("SELECT user_id FROM %s WHERE username = '%s'" % ('user', username))
            user_id = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("INSERT INTO %s (fk_user_id, fk_task_id) VALUES (%d, %d)" % ('user_has_task', user_id, task_id))
            self.conn.commit()
            cursor.close()

        except Exception as error:
            print(error)
    
    def remove_task(self, username, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT user_id FROM %s WHERE username = '%s'" % ('user', username))
            user_id = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("DELETE FROM %s WHERE fk_task_id = '%s' AND fk_user_id = %d" % ('user_has_task', task_id, user_id))
            self.conn.commit()
            cursor.close()
    
            cursor = self.conn.cursor()
            cursor.execute("DELETE FROM %s WHERE task_id = '%s'" % ('task', task_id))
            self.conn.commit()
            cursor.close()

        except Exception as error:
            print(error)

    def info_task(self, username, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT title FROM %s WHERE task_id = '%s'" % ('task', task_id))
            title = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("SELECT begin FROM %s WHERE task_id = '%s'" % ('task', task_id))
            begin = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("SELECT end FROM %s WHERE task_id = '%s'" % ('task', task_id))
            end = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("SELECT status FROM %s WHERE task_id = '%s'" % ('task', task_id))
            status = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()
            return render_template("form_modif.html", username = username, task_id = task_id, title = title, begin = begin, end = end, status = status)
        except Exception as error:
            print(error)

    def modif_task(self, username, task_id, title, begin, end, status):
        try:
            cursor = self.conn.cursor()
            cursor.execute("UPDATE task SET title = '%s' WHERE task_id = '%s'" % (title, task_id))
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("UPDATE task SET begin = '%s' WHERE task_id = '%s'" % (begin, task_id))
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("UPDATE task SET end = '%s' WHERE task_id = '%s'" % (end, task_id))
            self.conn.commit()
            cursor.close()

            cursor = self.conn.cursor()
            cursor.execute("UPDATE task SET status = '%s' WHERE task_id = '%s'" % (status, task_id))
            self.conn.commit()
            cursor.close()
        except Exception as error:
            print(error)


class Task(object):
    def __init__(self, app, conn):
        self.app = app
        self.conn = conn
    
    def find_user_id(self, username):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT user_id FROM %s WHERE username = '%s'" % ('user', username))
            user_id = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()
            return user_id
        except Exception as error:
            print(error)

    def task_id_exist(self, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT COUNT(1) FROM %s WHERE task_id = %d" % ('task', task_id))
            exist = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()
            return True if exist == 1 else False
        except Exception as error:
            print(error)
        return True

    def find_task_id(self, user_id, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT COUNT(1) FROM %s WHERE fk_task_id = %d && fk_user_id = %d" % ('user_has_task', task_id, user_id))
            exist = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()
            return True if exist == 1 else False
        except Exception as error:
            print(error)
        return True

    def find_list(self, task_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT * FROM %s WHERE task_id = %d" % ('task', task_id))
            task = list(cursor.fetchall()[0])
            self.conn.commit()
            cursor.close()
            return task
        except Exception as error:
            print(error)


    def get_nb_task(self, user_id):
        try:
            cursor = self.conn.cursor()
            cursor.execute("SELECT COUNT(*) FROM %s WHERE fk_user_id = %s" % ('user_has_task', user_id))
            nb = cursor.fetchone()[0]
            self.conn.commit()
            cursor.close()
            return nb
        except Exception as error:
            print(error)