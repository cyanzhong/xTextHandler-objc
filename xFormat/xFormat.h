//
//  xFormat.h
//  xTextHandler
//
//  Created by cyan on 16/6/19.
//  Copyright © 2016年 cyan. All rights reserved.

//  Thanks to: https://github.com/vkiryukhin/vkBeautify
//
//  The MIT License (MIT)
//
//  Copyright (c) 2013 Vadim Kiryukhin
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

static const NSInteger xFormatIndentationWidth = 4;

static JSContext *JavaScriptContext() {
    static JSContext *context;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        context = [[JSContext alloc] init];
        NSString *path = [[NSBundle mainBundle] pathForResource:@"vkbeautify" ofType:@"js"];
        NSString *js = [NSString stringWithContentsOfFile:path
                                                 encoding:NSUTF8StringEncoding
                                                    error:nil];
        [context evaluateScript:js];
    });
    return context;
}

static NSString *vkBeautify(NSString *string, NSString *type) {
    JSValue *parser = JavaScriptContext()[@"parser"][type];
    JSValue *pretty = [parser callWithArguments:@[string, @(xFormatIndentationWidth)]];
    return pretty.isUndefined ? string : pretty.toString;
}
