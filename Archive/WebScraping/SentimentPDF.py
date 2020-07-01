from textblob import TextBlob
import PyPDF2

#This program runs sentiment analysis after extracting text from PDF files.

#Selecting the file.
FILE_PATH = 'test.pdf'

#Opening the PDF file.
with open(FILE_PATH, mode='rb') as f: #read-binary mode
    reader = PyPDF2.PdfFileReader(f)
    page = reader.getPage(0) #get the first page
    blobpdf = TextBlob(page.extractText()) #extract all the text from the page.
    print('The document title is: ' +str(FILE_PATH))
    print('The number of pages in this document is: ' +str(reader.numPages))
    print('Analysis: ' +str(blobpdf.sentiment))
    print('The full text is: ')
    print(blobpdf)
    
    
