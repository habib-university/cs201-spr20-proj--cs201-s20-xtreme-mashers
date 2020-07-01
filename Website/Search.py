import requests
from bs4 import BeautifulSoup
import json

def scrape(text):
    lst = []
    #for text in list_of_words:
    user_search = text
    #print("Running your search...")
    #print('')
    #print('')

    # The get function gets all the data from the page link we enter.
    gsearch = requests.get("https://www.google.com/search?q=" + user_search)
    r_word = requests.get("https://keywordtool.io/search/keywords/google/53115825?category=web&keyword="+ user_search+"&country=PK&language=en-PK#suggestions")
    # This function converts the extracted data into html parser format, Ez to read.
    soup = BeautifulSoup(gsearch.text, 'html.parser')
    # print(soup.prettify())
    soupier = BeautifulSoup(r_word.text, 'html.parser')
    # We select the class and object within the html code to print out only
    # select parts of it, allowing us to extract only the URL.
    # print (soup)
    # result = soup.select('.BNeawe a')
    tags = soup.find_all('a')
    # Extracting URLs from the attribute href in the <a> tags.

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
    #print(lst)
    return lst
    #lst = []
    #grbg = ["http", "&sa", "%3Fref", "/search?ie=UTF-8&q=COVID-19"]
    #for i in result[0:51]: #loop to get first 10 links.
        #initial_link = i.get('href') #grab the base url from our scraped data.
        #for x in grbg:
            #if x in initial_link:  #Remove unwanted prefixes and suffixes from urls.
                #slicer = initial_link.find(x)
                #initial_link = initial_link[int(slicer):]
            #if "&sa" in initial_link:
                #slicer = initial_link.find("&sa")
                #initial_link = initial_link[:int(slicer)]
            #elif "%3Fref" in initial_link:
                #slicer = initial_link.find("%3Fref")
                #initial_link = initial_link[:int(slicer)]
        #elif "www." in initial_link:
            #slicer = initial_link.find("www.")
            #initial_link = initial_link[int(slicer):]
            #if "&sa" in initial_link:
                #slicer = initial_link.find("&sa")
                #initial_link = initial_link[:int(slicer)]
            #elif "%3Fref" in initial_link:
                #slicer = initial_link.find("%3Fref")
                #initial_link = initial_link[:int(slicer)]
        #lst.append(initial_link)
    #return lst
def helper(text):
    related_words = [text]
    for word in get_related_keywords(text):
        related_words.append(word)
    return related_words

def sort(a):
    lst2 = ["cnn", "bbc", "guardian", "reuters", "who.int", ".org", ".edu", "official"]
    lst1 = [".info", "wiki"]
    dict = {}
    dict[0] = []
    dict[1] = []
    dict[-1] = []
    imp = []
    added_in_lst1 = False
    added_in_lst2 = False
    for i in a:
        #print(i)
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
    #for i in dict[1]:
        #imp.append(dict[1][x])
    return dict

def get_related_keywords(text):
    user_search = text
    #print("Running your search...")
    #print('')
    #print('')
    lst_of_related_words = []
    # The get function gets all the data from the page link we enter.
    gsearch = requests.get("https://api.bing.com/osjson.aspx?query=" + user_search)
    for i in gsearch.text.split(","):
        i = i.replace('"',"").replace('[',"").replace(']', "")
        lst_of_related_words.append(i)
    return lst_of_related_words[1:]


def scrape_on_keywords(related_keywords):
    final_lst = []
    total_links = 0;
    for a in related_keywords:
        #print(a)
        out = (scrape(a))
        #print(out)
        total_links += len(out)
        my_dict = sort(out)
        #print(my_dict)
        for item in process_dict(my_dict):
            final_lst.append(item)
    #print(final_lst)
    #print(len(final_lst))
    #print(total_links)
    return final_lst

def process_dict(my_dict : dict):
    mylst = my_dict.get(1)
    print(mylst)
    return mylst


text = "cat"
#print("all keywords are: ", related_words)

scrape_on_keywords(helper(text))

