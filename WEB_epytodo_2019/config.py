import os

DATABASE_NAME=os.getenv('DATABASE_NAME', 'epytodo')
DATABASE_HOST=os.getenv('DATABASE_HOST', 'localhost')
DATABASE_SOCK=os.getenv('DATABASE_SOCK', None)
DATABASE_USER=os.getenv('DATABASE_USER', 'root')
DATABASE_PASS=os.getenv('DATABASE_PASS', 'test')

MAX_DB_CON_RETRY = 10
db_CON_delay = 5