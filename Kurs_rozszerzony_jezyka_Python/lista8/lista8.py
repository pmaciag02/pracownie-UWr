import http.client
from keys import key1
from keys import key2

conn = http.client.HTTPSConnection("apidojo-yahoo-finance-v1.p.rapidapi.com")

headers = {
    'X-RapidAPI-Key': key1,
    'X-RapidAPI-Host': "apidojo-yahoo-finance-v1.p.rapidapi.com"
    }

conn.request("GET", "/auto-complete?q=tesla&region=US", headers=headers)

res = conn.getresponse()
data = res.read()

print(data.decode("utf-8"))

conn2 = http.client.HTTPSConnection("contextualwebsearch-websearch-v1.p.rapidapi.com")

headers2 = {
    'X-RapidAPI-Key': key2,
    'X-RapidAPI-Host': "contextualwebsearch-websearch-v1.p.rapidapi.com"
    }

conn2.request("GET", "/api/spelling/SpellCheck?text=teylor%20swiift", headers=headers)

res2 = conn2.getresponse()
data2 = res2.read()

print(data2.decode("utf-8"))