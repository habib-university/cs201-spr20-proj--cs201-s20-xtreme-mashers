from flask import Flask, render_template, request

app = Flask(__name__)


@app.route('/')
def index():
    return render_template("Search.html")

@app.route('/', methods=['POST'])
def myform():
    text= request.form['search']
    return text

if __name__ == "__main__":
    app.run(debug = True)
