//
//  xRadixCommand.m
//  xRadix
//
//  Created by cyan on 16/6/18.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import "xRadixCommand.h"
#import "xRadix.h"
#import "xTextModifier.h"

@implementation xRadixCommand

- (NSDictionary *)handlers {
    static NSDictionary *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = @{
            @"xradix.hex": ^NSString *(NSString *text) { return Hex(text); },
            @"xradix.bin": ^NSString *(NSString *text) { return Bin(text); },
            @"xradix.oct": ^NSString *(NSString *text) { return Oct(text); },
            @"xradix.dec": ^NSString *(NSString *text) { return Dec(text); },
        };
    });
    return _instance;
}

- (void)performCommandWithInvocation:(XCSourceEditorCommandInvocation *)invocation completionHandler:(void (^)(NSError * _Nullable nilOrError))completionHandler {
    [xTextModifier radix:invocation handler:self.handlers[invocation.commandIdentifier]];
    completionHandler(nil);
}

@end
