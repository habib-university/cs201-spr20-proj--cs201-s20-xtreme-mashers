from flask import Flask, render_template, request
import requests, webbrowser
from bs4 import BeautifulSoup
import Search

app = Flask(__name__)

def scrape(text):
    return Search.scrape(text)
# def scrape(text):
#     user_search = text
#     print("Running your search...")
#     print('')
#     print('')

#     #The get function gets all the data from the page link we enter.
#     gsearch = requests.get("https://www.google.com/search?q="+user_search)

#     #This function converts the extracted data into html parser format, Ez to read.
#     soup = BeautifulSoup(gsearch.text, 'html.parser')
#     #print(soup.prettify())

#     #We select the class and object within the html code to print out only
#     #select parts of it, allowing us to extract only the URL.
#     result = soup.select('.BNeawe a')

#     #Creating a dictionary to present an organized results screen.
#     dict={}
#     n=0
#     for i in result[0:11]: #loop to get first 10 links.
#         initial_link = i.get('href') #grab the base url from our scraped data.
#         if "http" in initial_link: #Remove unwanted prefixes and suffixes from urls.
#             slicer = initial_link.find("http")
#             initial_link = initial_link[int(slicer):]
#             if "&sa" in initial_link:
#                 slicer = initial_link.find("&sa")
#                 initial_link = initial_link[:int(slicer)]
#             elif "%3Fref" in initial_link:
#                 slicer = initial_link.find("%3Fref")
#                 initial_link = initial_link[:int(slicer)]
#             else:
#                 pass
#         elif "www." in initial_link:
#             slicer = initial_link.find("www.")
#             initial_link = initial_link[int(slicer):]
#             if "&sa" in initial_link:
#                 slicer = initial_link.find("&sa")
#                 initial_link = initial_link[:int(slicer)]
#             elif "%3Fref" in initial_link:
#                 slicer = initial_link.find("%3Fref")
#                 initial_link = initial_link[:int(slicer)]
#             else:
#                 pass
#         dict[n]=initial_link
#         n+=1
#     return dict


@app.route('/')
def index():
    return render_template("Search.html")

@app.route('/', methods=['POST'])
def myform():
    text= request.form['search']
    return text

if __name__ == "__main__":
    app.run(debug = True)


