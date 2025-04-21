filetype = input("File name: ")


filetype = filetype.strip().lower()

if filetype.endswith(".gif"):
    print("image/gif")
elif filetype.endswith(".jpg") or filetype.endswith(".jpeg"):
    print("image/jpeg")
elif filetype.endswith(".png"):
    print("image/png")
elif filetype.endswith(".pdf"):
    print("application/pdf")
elif filetype.endswith(".txt"):
    print("text/plain")
elif filetype.endswith(".zip"):
    print("application/zip")
else:
    print("application/octet-stream")
