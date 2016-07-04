//
//  xSearchCommand.m
//  xSearch
//
//  Created by cyan on 16/6/19.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import "xSearchCommand.h"
#import "xSearch.h"

@implementation xSearchCommand

- (NSDictionary *)handlers {
    static NSDictionary *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = @{
            @"xsearch.google": ^NSString *(NSString *text) { return Search(text, @"google"); },
            @"xsearch.developer": ^NSString *(NSString *text) { return Search(text, @"developer"); },
            @"xsearch.translate": ^NSString *(NSString *text) { return Search(text, @"translate"); },
            @"xsearch.stackoverflow": ^NSString *(NSString *text) { return Search(text, @"stackoverflow"); },
            @"xsearch.github": ^NSString *(NSString *text) { return Search(text, @"github"); },
            @"xsearch.dash": ^NSString *(NSString *text) { return Search(text, @"dash"); },
            @"xsearch.dict":  ^NSString *(NSString *text) { return PerformService(text, @"Look Up in Dictionary"); },
        };
    });
    return _instance;
}

@end
