//
//  xTextCommand.m
//  xTextHandler
//
//  Created by cyan on 16/6/20.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import "xTextCommand.h"
#import "xTextModifier.h"

@implementation xTextCommand


/**
 Handlers map

 @return implement in subclass
 */
- (NSDictionary *)handlers {
    return @{};
}


/**
 Texts handling method
 
 If you want to match any text, do nothing in subclass
 If you want to match text with your pattern, override this method in subclass

 @param invocation        XCSourceEditorCommandInvocation
 @param completionHandler nil or Error
 */
- (void)performCommandWithInvocation:(XCSourceEditorCommandInvocation *)invocation completionHandler:(void (^)(NSError * _Nullable nilOrError))completionHandler {
    [xTextModifier any:invocation handler:self.handlers[invocation.commandIdentifier]];
    completionHandler(nil);
}

@end
