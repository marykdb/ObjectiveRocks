//
//  RocksDBWriteBatch+Private.h
//  ObjectiveRocks
//
//  Created by Iska on 11/01/15.
//  Copyright (c) 2015 BrainCookie. All rights reserved.
//

#import "RocksDBWriteBatch.h"
#import "RocksDBColumnFamilyHandle.h"

namespace rocksdb {
	class DB;
	class ColumnFamilyHandle;
	class WriteBatchBase;
}

/**
 This category is intended to hide all C++ types from the public interface in order to
 maintain a pure Objective-C API for Swift compatibility.
 */
@interface RocksDBWriteBatch (Private)

/** @brief The rocksdb::WriteBatchBase associated with this instance. */
@property (nonatomic, readonly) rocksdb::WriteBatch *writeBatch;

/**
 Initializes a new instance of `RocksDBWriteBatch` with the given native rocksdb::WriteBatchBase 
 instance, encoding options and RocksDBColumnFamilyHandle instance.

 @discussion This initializer is used by the subclasses of `RocksDBWriteBatch`.

 @param writeBatchBase An instance of a concrete subclass implementation of rocksdb::WriteBatchBase.
 @param columnFamily The RocksDBColumnFamilyHandle instance.
 @return a newly-initialized instance of `RocksDBWriteBatch`.
 */
- (instancetype)initWithNativeWriteBatch:(rocksdb::WriteBatch *)writeBatchBase
							columnFamily:(RocksDBColumnFamilyHandle *)columnFamily;

/**
 Initializes a new instance of a simple `RocksDBWriteBatch` with the given options and
 rocksdb::ColumnFamilyHandle instance.

 @param columnFamily The RocksDBColumnFamilyHandle instance.
 @return a newly-initialized instance of `RocksDBWriteBatch`.
 */
- (instancetype)initWithColumnFamily:(RocksDBColumnFamilyHandle *)columnFamily;

@end
