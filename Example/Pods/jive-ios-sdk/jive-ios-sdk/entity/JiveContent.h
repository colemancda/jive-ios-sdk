//
//  JiveContent.h
//  jive-ios-sdk
//
//  Created by Jacob Wright on 11/13/12.
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

#import "JiveTypedObject.h"
#import "JivePerson.h"
#import "JiveContentBody.h"
#import "JiveSummary.h"


extern struct JiveContentStatusValues {
    __unsafe_unretained NSString *incomplete; // Content is in draft mode
    __unsafe_unretained NSString *pendingApproval; // Content is waiting for approval
    __unsafe_unretained NSString *rejected; // Content has been rejected for publication by an approver;
    __unsafe_unretained NSString *scheduled; // Content has been scheduled to be published on a given date
    __unsafe_unretained NSString *published; // Content has been published
} const JiveContentStatusValues;


extern struct JiveContentAttributes {
    __unsafe_unretained NSString *author;
    __unsafe_unretained NSString *content;
    __unsafe_unretained NSString *contentID;
    __unsafe_unretained NSString *contentImages;
    __unsafe_unretained NSString *contentVideos;
    __unsafe_unretained NSString *followerCount;
    __unsafe_unretained NSString *highlightBody;
    __unsafe_unretained NSString *highlightSubject;
    __unsafe_unretained NSString *highlightTags;
    __unsafe_unretained NSString *iconCss;
    __unsafe_unretained NSString *jiveId;
    __unsafe_unretained NSString *likeCount;
    __unsafe_unretained NSString *parent;
    __unsafe_unretained NSString *parentContent;
    __unsafe_unretained NSString *parentContentVisible;
    __unsafe_unretained NSString *parentPlace;
    __unsafe_unretained NSString *parentVisible;
    __unsafe_unretained NSString *published;
    __unsafe_unretained NSString *replyCount;
    __unsafe_unretained NSString *status;
    __unsafe_unretained NSString *subject;
    __unsafe_unretained NSString *tags;
    __unsafe_unretained NSString *updated;
    __unsafe_unretained NSString *viewCount;
    __unsafe_unretained NSString *visibleToExternalContributors;
    __unsafe_unretained NSString *root;
    __unsafe_unretained NSString *note;
} const JiveContentAttributes;


//! \class JiveContent
//! https://docs.developers.jivesoftware.com/api/v3/cloud/rest/ContentEntity.html
@interface JiveContent : JiveTypedObject

//! Author of this content object.
@property(nonatomic, readonly, strong) JivePerson* author;

//! Content of this content object.
@property(nonatomic, strong) JiveContentBody* content;

//! Internal Jive ID associated with the content.
@property(nonatomic, readonly, copy) NSString *contentID;

//! Image data for embedded images. JiveImage[]
@property(nonatomic, readonly, strong) NSArray *contentImages;

//! Video data for embedded videos. JiveContentVideo[]
@property(nonatomic, readonly, strong) NSArray *contentVideos;

//! Number of people following this object.
@property(nonatomic, readonly, strong) NSNumber *followerCount;

//! Highlight snippet of a search match in the body or description.
@property(nonatomic, readonly, copy) NSString* highlightBody;

//! Highlight snippet of a search match in the subject or name.
@property(nonatomic, readonly, copy) NSString* highlightSubject;

//! Highlight snippet of a search match in tags.
@property(nonatomic, readonly, copy) NSString* highlightTags;

//! CSS Style to locate icon within sprite.
@property(nonatomic, readonly, copy) NSString *iconCss;

//! Identifier (unique within an object type and Jive instance) of this object. This field is internal to Jive and should not be confused with contentID or placeID used in URIs.
@property(nonatomic, readonly, copy) NSString* jiveId;

//! Number of people who have liked this object.
@property(nonatomic, readonly, strong) NSNumber *likeCount;

//! URI of the parent place of this content object. When visibility is place then the URI points to a place (and is required on create). Otherwise, this field is not part of the returned JSON (and must not be included on create).
@property(nonatomic, copy) NSString* parent;

//! Summary information about the content object that is the parent of this object. Availability: Will be present in search results only.
@property(nonatomic, readonly, strong) JiveSummary* parentContent;

//! Flag indicating that the content parent's contents are visible to the viewer.
@property(nonatomic, readonly, strong) NSNumber *parentContentVisible;
- (BOOL) isParentContentVisible;

//! Summary information about the place that contains this object. Availability: Will be present in search results only.
@property(nonatomic, readonly, strong) JiveSummary* parentPlace;

//! Flag indicating that the content parent is visible to the viewer.
@property(nonatomic, readonly, strong) NSNumber *parentVisible;
- (BOOL) isParentVisible;

//! Date and time when this content object was originally created.
@property(nonatomic, readonly, strong) NSDate* published;

//! Number of replies to this object.
@property(nonatomic, readonly, strong) NSNumber *replyCount;

//! Published status of this content object.
//! * incomplete - Content object is in draft mode
//! * pending_approval - Content object is waiting for approval
//! * rejected - Content object has been rejected for publication by an approver
//! * published - Content object has been published
@property(nonatomic, readonly, copy) NSString* status;

//! Subject of this content object.
@property(nonatomic, copy) NSString* subject;

//! Tags associated with this object. Availability: Will be present only for object types that support tags. NSString[]
@property(nonatomic, strong) NSArray *tags;

//! Date and time this content object was most recently updated.
@property(nonatomic, readonly, strong) NSDate* updated;

//! Number of times this content object has been viewed. Availability: Will be present only for objects that support view counts
@property(nonatomic, readonly, strong) NSNumber *viewCount;

//! Flag indicating that this content object is potentially visible to external contributors.
@property(nonatomic, strong) NSNumber *visibleToExternalContributors;
- (BOOL)isVisibleToExternalContributors;

//! The action item note specified when content is shared
@property(nonatomic, readonly, copy) NSString* note;

//! The URI for the actual content being shared
@property(nonatomic, readonly, strong) NSURL *root;

- (NSURL *)childOutcomeTypesRef;
- (NSURL *)extPropsRef;
- (BOOL)canAddExtProps;
- (BOOL)canDeleteExtProps;
- (NSURL *)htmlRef;
- (NSURL *)likesRef;
- (BOOL)canLike;
- (BOOL)canUnlike;
- (NSURL *)outcomesRef;
- (BOOL)canAddOutcomes;
- (NSURL *)outcomeTypesRef;
- (NSURL *)readRef;
- (BOOL)canMarkAsRead;
- (BOOL)canMarkAsUnread;

- (NSURL *)attachmentsRef;
- (NSURL *)commentsRef;
- (BOOL)canAddComments;
- (NSURL *)followingInRef;
- (NSURL *)imagesRef;
- (NSURL *)messagesRef;
- (BOOL)canAddMessage;
- (NSURL *)versionsRef;

- (NSURL *)votesRef;
- (BOOL)canVote;

@end
