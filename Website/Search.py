import requests
from bs4 import BeautifulSoup

def scrape(text):
    user_search = text
    print("Running your search...")
    print('')
    print('')

    # The get function gets all the data from the page link we enter.
    gsearch = requests.get("https://www.google.com/search?q=" + user_search)
    r_word = requests.get("https://keywordtool.io/search/keywords/google/53115825?category=web&keyword="+ user_search+"&country=PK&language=en-PK#suggestions")
    # This function converts the extracted data into html parser format, Ez to read.
    soup = BeautifulSoup(gsearch.text, 'html.parser')
    # print(soup.prettify())
    soupier = BeautifulSoup(r_word, 'html.parser')
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
def helper():
    pass

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
    for i in dict[1]:
        imp.append(dict[1][x])
    return imp

def get_related_keywords(text):
    user_search = text
    print("Running your search...")
    print('')
    print('')

    # The get function gets all the data from the page link we enter.
    gsearch = requests.get("https://www.google.com/search?q=" + user_search)
    soup = BeautifulSoup(gsearch.text, 'html.parser')
    lst = []
    lst_of_related_words = []
    name_box = soup.find_all('div', attrs={'class': 'BNeawe deIvCb AP7Wnd'})
    start_collecting = False
    for a in name_box:
        if start_collecting:
            name = a.text.strip()
            lst_of_related_words.append(name)
        if "Related searches" in str(a):
            start_collecting = True

    tags = soup.find_all('')
    for i in tags:  # loop to get first 10 links.
        print (" i is : ", i)
        initial_link = i.get('href')  # grab the base url from our scraped data.
        # print("initial link is : ", initial_link)
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
    print(lst_of_related_words)
    return lst_of_related_words
# out = (scrape("habib university"))
# print(out)
# print(len(out))
# print(sort(scrape("habib university")))