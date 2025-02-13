#!/usr/bin/python

import cgi
import os
import sys
from urllib.parse import unquote
import cgitb
cgitb.enable()

content_length = int(os.environ.get("CONTENT_LENGTH", 5))
file_content = sys.stdin.read(content_length)
print(file_content)
print(content_length)

form = cgi.FieldStorage()
request_method = os.environ.get("REQUEST_METHOD").upper()
route = unquote("." + os.environ.get("PATH_TRANSLATED"))
print(route)
# exit()

# if request_method == "POST":
#     if "file" in form and form["file"].filename:
#         file_item = form["file"]
#         current_dir = os.path.dirname(os.path.abspath(__file__))
#         filename = os.path.join(current_dir, file_item.filename)
#         with open(filename, "wb") as file:
#             file.write(file_item.file.read())
#         print("<html><body style='font-family: Arial; sans-serif;margin: 20px;'>")
#         print("<div>File uploaded successfully.</div>")
#         print("<div>Uploaded File: {}</div>".format(filename))
#         print("</body></html>")
#     else:
#         print("No file uploaded.")
# else:
#     print("Invalid request method.")