from flask import Flask, render_template, request
import requests
import webbrowser
from bs4 import BeautifulSoup
import json
from json2html import *
import time

app = Flask(__name__)

def scrape(text):
    user_search = text
    print("Running your search...")
    print('')
    print('')

    # The get function gets all the data from the page link we enter.
    gsearch = requests.get("https://www.google.com/search?q=" + user_search)

    # This function converts the extracted data into html parser format, Ez to read.
    soup = BeautifulSoup(gsearch.text, 'html.parser')
    # print(soup.prettify())

    # We select the class and object within the html code to print out only
    # select parts of it, allowing us to extract only the URL.
    # print (soup)
    # result = soup.select('.BNeawe a')
    tags = soup.find_all('a')

    # Extracting URLs from the attribute href in the <a> tags.

    # for tag in tags:
    #   print ("--------")
    #   print(tag.get('href'))

    # print(result)
    # for i in result:
    #    print (i)
    # Creating a dictionary to present an organized results screen.
    lst = []
    for i in tags:  # loop to get first 10 links.
        initial_link = i.get('href')  # grab the base url from our scraped data.
        #print("initial link is : ", initial_link)
        if "http" in initial_link:  # Remove unwanted prefixes and suffixes from urls.
            slicer = initial_link.find("http")
            initial_link = initial_link[int(slicer):]
            if "&sa" in initial_link:
                slicer = initial_link.find("&sa")
                initial_link = initial_link[:int(slicer)]
            elif "%3Fref" in initial_link:
                slicer = initial_link.find("%3Fref")
                initial_link = initial_link[:int(slicer)]
            lst.append(initial_link)
        elif "www." in initial_link:
            slicer = initial_link.find("www.")
            initial_link = initial_link[int(slicer):]
            if "&sa" in initial_link:
                slicer = initial_link.find("&sa")
                initial_link = initial_link[:int(slicer)]
            elif "%3Fref" in initial_link:
                slicer = initial_link.find("%3Fref")
                initial_link = initial_link[:int(slicer)]
            lst.append(initial_link)
    return lst

def sort(a):
    lst2 = ["cnn", "bbc", "guardian", "reuters", "who.int", ".org", ".edu"]
    lst1 = ["worldometer", ".info", "wiki"]
    dict = {}
    dict[0] = []
    dict[1] = []
    dict[-1] = []
    added_in_lst1 = False
    added_in_lst2 = False
    for i in a:
        for j in lst1:
            if j in i:
                dict.get(0).append(i)
                added_in_lst1 = True
                break
        if not added_in_lst1:
            for x in lst2:
                if x in i:
                    dict.get(1).append(i)
                    added_in_lst2 = True
                    break
            if not added_in_lst2:
                dict.get(-1).append(i)
        added_in_lst1 = False
        added_in_lst2 = False
    return dict


@app.route('/')
def index():
    return render_template("Search.html")


@app.route('/', methods=['POST'])
def myform():
    text = request.form['search']
    text = json2html.convert(json = json.dumps(sort(scrape(text))))
    text_file = open("templates/data.html", "w")
    n = text_file.write(text)
    text_file.close()
    return render_template("index.html")


if __name__ == "__main__":
    app.run(debug = True)

