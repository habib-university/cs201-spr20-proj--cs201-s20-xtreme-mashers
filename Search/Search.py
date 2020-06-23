import requests
from bs4 import BeautifulSoup

def scrape(text):
    user_search = text
    print("Running your search...")
    print('')
    print('')

    #The get function gets all the data from the page link we enter.
    gsearch = requests.get("https://www.google.com/search?q="+user_search)

    #This function converts the extracted data into html parser format, Ez to read.
    soup = BeautifulSoup(gsearch.text, 'html.parser')
    #print(soup.prettify())

    #We select the class and object within the html code to print out only
    #select parts of it, allowing us to extract only the URL.
    result = soup.select('.BNeawe a')

    #Creating a dictionary to present an organized results screen.
    lst = []
    for i in result[0:11]: #loop to get first 10 links.
        initial_link = i.get('href') #grab the base url from our scraped data.
        if "http" in initial_link: #Remove unwanted prefixes and suffixes from urls.
            slicer = initial_link.find("http")
            initial_link = initial_link[int(slicer):]
            if "&sa" in initial_link:
                slicer = initial_link.find("&sa")
                initial_link = initial_link[:int(slicer)]
            elif "%3Fref" in initial_link:
                slicer = initial_link.find("%3Fref")
                initial_link = initial_link[:int(slicer)]
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
    lst1 = ["cnn", "bbc", "guardian", "reuters", "who.int", ".org"]
    lst2 = ["worldometer", ".pk", ".info"]
    n = 0
    dict = {}
    for i in a:
        for j in lst1:
            if j in i:
                n = 1
                if n not in dict:
                    dict[n] = i
                else:
                    dict[n].append(i)
        for x in lst2:
            if x in i:
                n = 0
                if n not in dict:
                    dict[n] = i
                else:
                    dict[n].append(i)
            else:
                n = -1
                if n not in dict:
                    dict[n] = i
                else:
                    dict[n].append(i)
    return dict

print(sort(scrape("corona")))
#print(scrape("corona"))
#print(len(scrape("corona")))