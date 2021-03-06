//
//  ContentLikedBy.m
//  jive-ios-sdk-tests
//
//  Created by Shivkumar Krishnan on 1/23/13.
//
//    Copyright 2013 Jive Software Inc.
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//    http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//


#import "QEDocumentTests.h"
#import "JVUtilities.h"

@interface ContentLikedBy : QEDocumentTests

@end

@implementation ContentLikedBy

- (void) testContentLikedBy {
    
    NSString* contentURL = [self.testContent.selfRef absoluteString];
    
    // Make API call
    // Get the likes count for the doc
    
    NSString* likesForContentAPIURL = [contentURL stringByAppendingString:@"/likes"];
    
    id jsonResponseFromAPI = [JVUtilities getAPIJsonResponse:userid1 pw:pw1 URL:likesForContentAPIURL];
    NSArray* returnedLikesListFromAPI= [jsonResponseFromAPI objectForKey:@"list"];
    NSUInteger returnedLikesListCountFromAPI = [returnedLikesListFromAPI count];
    	
    JivePagedRequestOptions* options = [[JivePagedRequestOptions alloc] init];
    options.startIndex = 0;
    
    __block NSArray *returnedLikesListFromSDK = nil;
    
    waitForTimeout(^(dispatch_block_t finishBlock2) {
        [jive1 contentLikedBy:self.testContent withOptions:options onComplete:^(NSArray *results) {
            returnedLikesListFromSDK = results;
            
            finishBlock2();
        } onError:^(NSError *error) {
            STFail([error localizedDescription]);
            finishBlock2();
        }];
    });
    
    STAssertEquals([returnedLikesListFromSDK count], returnedLikesListCountFromAPI, @"Expecting same results from SDK and v3 API for likes count on this document!");    
}

@end
