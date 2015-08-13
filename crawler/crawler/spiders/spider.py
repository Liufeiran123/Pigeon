import scrapy
from scrapy.http import Request
from scrapy.selector import Selector
from ..items import CrawlerItem

from ..TextExtractor import TextExtractor


import re

class DmozSpider(scrapy.Spider):
    name = "dmoz"
    start_urls = [
	"http://www.cnblogs.com/"
    ]

    pattern = re.compile(r'^http')
    te = TextExtractor()

    def parse(self, response):
        item = CrawlerItem()

        item['url'] = response.url.encode('utf-8')
        item['title'] = response.xpath('//title/text()').extract()[0].encode('utf-8')

        if response.encoding == 'utf-8':
            item['body'] = response.body
        else:
            item['body'] = response.body.decode(response.encoding).encode('utf-8')

        c = item['body'].decode("utf-8")

        c = DmozSpider.te.extract(c)
        c = c.encode('utf-8')
        item['text'] = c

        yield item

    	#link = response.xpath('//a/@href').extract()
        #for item_url in link:
        #    if DmozSpider.pattern.match(item_url):
        #       yield Request(item_url, callback=self.parse)
            
