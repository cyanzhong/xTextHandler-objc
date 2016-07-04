//
//  xColorCommand.m
//  xColor
//
//  Created by cyan on 16/6/19.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import "xColorCommand.h"
#import "xColor.h"
#import "xTextModifier.h"

@implementation xColorCommand

- (NSDictionary *)handlers {
    static NSDictionary *_instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = @{
            @"xcolor.hex": ^NSString *(NSString *text) { return HexColor(text); },
            @"xcolor.rgb": ^NSString *(NSString *text) { return RgbColor(text); },
            @"xcolor.preview": ^NSString *(NSString *text) { return PreviewColor(text); },
        };
    });
    return _instance;
}

- (void)performCommandWithInvocation:(XCSourceEditorCommandInvocation *)invocation completionHandler:(void (^)(NSError * _Nullable nilOrError))completionHandler {
    
    NSString *identifier = invocation.commandIdentifier;
    NSString *(^handler)(NSString *text) = self.handlers[identifier];
    
    if ([identifier hasSuffix:@"hex"]) {
        [xTextModifier rgb:invocation handler:handler];
    } else if ([identifier hasSuffix:@"rgb"]) {
        [xTextModifier hex:invocation handler:handler];
    } else if ([identifier hasSuffix:@"preview"]) {
        [xTextModifier any:invocation handler:handler];
    }
    
    completionHandler(nil);
}

@end
