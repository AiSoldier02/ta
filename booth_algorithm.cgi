#!/usr/bin/env python3
import cgi
import subprocess

print("Content-Type: text/html")
print()

form = cgi.FieldStorage()
multiplicand = form.getvalue("multiplicand")
multiplier = form.getvalue("multiplier")

result = subprocess.run(["./booth_algorithm", multiplicand, multiplier], capture_output=True, text=True)
output = result.stdout

print(f"<html><body><h1>Booth's Algorithm Result</h1><p>{output}</p></body></html>")
