from jensen import Queue
from bottle import route, run, template, response, Bottle
import json

API_VERSION = 'v1'

QUEUE = Queue()
APP = Bottle()

@APP.route('/')
def index():
    response.content_type = 'text/html'
    return template('<h1>Jensen Queue</h1>')

@APP.route(f"/{API_VERSION}/reset/")
def apiIndex():
    global QUEUE
    response.content_type = 'application/json'
    QUEUE = Queue()
    payload = {
        'reset': True
    }
    return json.dumps(payload, indent=2)

@APP.route(f"/{API_VERSION}/")
def apiIndex():
    response.content_type = 'application/json'
    payload = {
        'size': QUEUE.size()
    }
    return json.dumps(payload, indent=2)

def main(host: str = '0.0.0.0', port: int = 8080):
    run(APP, host=host, port=port)
