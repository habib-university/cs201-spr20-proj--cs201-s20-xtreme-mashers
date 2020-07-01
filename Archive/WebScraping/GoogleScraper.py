import requests, webbrowser
from bs4 import BeautifulSoup

user_search = input("Enter your search query: ")
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

for i in result[0:11]: #loop to get first 10 links.
    print(i.get('href'))
    print('')
    break