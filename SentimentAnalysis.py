from textblob import TextBlob

#Generating some strings to run the analysis on.
Feedback1 = "The food at Xander's was awesome"
Feedback2 = "The environment and ambience at Xander's was very good"
Feedback3 = "The service at Xander's was okay"
Feedback4 = "The seating arrangement at Xander's was bad"

#Converting the strings into TextBlob objects so we can apply opertaions
blob1 = TextBlob(Feedback1)
blob2 = TextBlob(Feedback2)
blob3 = TextBlob(Feedback3)
blob4 = TextBlob(Feedback4)
blob5 = TextBlob(Feedback1 + Feedback2 + Feedback3 + Feedback4)
# also works: blob5 = blob1 +blob2 +blob3 +blob4

#Sentiment is a built-in function of the TextBlob library that renders the analysis
print(blob1.sentiment)
print(blob2.sentiment)
print(blob3.sentiment)
print(blob4.sentiment)
print(blob5.sentiment)
