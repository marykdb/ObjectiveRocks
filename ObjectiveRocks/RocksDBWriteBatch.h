//
//  RocksDBWriteBatch.h
//  ObjectiveRocks
//
//  Created by Iska on 02/12/14.
//  Copyright (c) 2014 BrainCookie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RocksDBOptions.h"

@interface RocksDBWriteBatch : NSObject

- (instancetype)initWithOptions:(RocksDBOptions *)options;

- (void)setObject:(id)anObject forKey:(id)aKey;
- (void)setData:(NSData *)data forKey:(NSData *)aKey;

- (void)deleteObjectForKey:(id)aKey;
- (void)deleteDataForKey:(NSData *)aKey;

- (void)clear;

- (int)count;
- (NSData *)data;
- (size_t)dataSize;

@end