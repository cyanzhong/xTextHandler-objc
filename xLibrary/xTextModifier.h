//
//  xTextModifier.h
//  xTextHandler
//
//  Created by cyan on 16/6/18.
//  Copyright © 2016年 cyan. All rights reserved.
//

#import <XcodeKit/XcodeKit.h>


/**
 Block for text handling

 @param text text

 @return modified text
 */
typedef NSString * (^xTextHandlerBlock) (NSString *text);

@interface xTextModifier : NSObject


/**
 Select text with regex

 @param invocation XCSourceEditorCommandInvocation
 @param pattern    regex pattern
 @param handler    handler
 */
+ (void)select:(XCSourceEditorCommandInvocation *)invocation pattern:(NSString *)pattern handler:(xTextHandlerBlock)handler;


/**
 Select any text

 @param invocation XCSourceEditorCommandInvocation
 @param handler    handler
 */
+ (void)any:(XCSourceEditorCommandInvocation *)invocation handler:(xTextHandlerBlock)handler;


/**
 Select numbers

 @param invocation XCSourceEditorCommandInvocation
 @param handler    handler
 */
+ (void)radix:(XCSourceEditorCommandInvocation *)invocation handler:(xTextHandlerBlock)handler;


/**
 Select hex color

 @param invocation XCSourceEditorCommandInvocation
 @param handler    handler
 */
+ (void)hex:(XCSourceEditorCommandInvocation *)invocation handler:(xTextHandlerBlock)handler;


/**
 Select RGB color

 @param invocation XCSourceEditorCommandInvocation
 @param handler    handler
 */
+ (void)rgb:(XCSourceEditorCommandInvocation *)invocation handler:(xTextHandlerBlock)handler;

@end
