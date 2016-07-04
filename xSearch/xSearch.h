//
//  xSearch.h
//  xTextHandler
//
//  Created by cyan on 16/6/19.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import <AppKit/AppKit.h>
#import "xEncode.h"
#import "xTextCommand.h"

static inline NSDictionary *Engines() {
    static NSDictionary *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = @{
            @"google": @"https://www.google.com/#newwindow=1&q=%@",
            @"developer": @"https://developer.apple.com/search/?q=%@",
            @"translate": @"http://translate.google.cn/?hl=en#en/zh-CN/%@",
            @"stackoverflow": @"http://stackoverflow.com/search?q=%@",
            @"github": @"https://github.com/search?q=%@",
            @"dash": @"dash://%@",
        };
    });
    return _instance;
}

static inline NSString *Search(NSString *string, NSString *type) {
    NSString *URL = [NSString stringWithFormat:Engines()[type], URLEncode(string)];
    [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:URL]];
    return string;
}

static inline NSString *PerformService(NSString *string, NSString *name) {
    [[NSPasteboard generalPasteboard] declareTypes:@[NSPasteboardTypeString] owner:nil];
    [[NSPasteboard generalPasteboard] setString:string forType:NSPasteboardTypeString];
    NSPerformService(name, [NSPasteboard generalPasteboard]);
    return string;
}
