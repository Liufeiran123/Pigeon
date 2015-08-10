# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class CrawlerItem(scrapy.Item):
    # define the fields for your item here like:
    # url
    url = scrapy.Field()
    # title
    title = scrapy.Field()
    # body
    body = scrapy.Field()
    # text
    text = scrapy.Field()
