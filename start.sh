#!/bin/bash

#start web server

cd web

python manage.py runserver &


#start crawler

cd ../
cd crawler/
scrapy  crawl dmoz


#start index

cd ../
cd index

python TextClient.py


#start search

cd ../
cd search

python SearchServer.py





