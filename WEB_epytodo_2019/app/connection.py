from app import *
import pymysql as sql

class connection(object):
    def __init__(self, app):
        self.conn = None
        self.app = app
        self.connect(app.config)

    def connect(self, config):
        try:
            self.conn = sql.connect(host=config['DATABASE_HOST'],
                                    user=config['DATABASE_USER'],
                                    passwd=config['DATABASE_PASS'],
                                    db=config['DATABASE_NAME']
                                    )
            if self.conn == None:
                raise Exception
        except Exception as error:
            print(error)
            exit(84)
    
    def disconect(self):
        self.conn.close()

    def get_connection(self):
        return self.conn