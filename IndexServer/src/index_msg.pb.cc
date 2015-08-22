// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: index_msg.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "index_msg.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* SingleItem_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SingleItem_reflection_ = NULL;
const ::google::protobuf::Descriptor* index_msg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  index_msg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_index_5fmsg_2eproto() {
  protobuf_AddDesc_index_5fmsg_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "index_msg.proto");
  GOOGLE_CHECK(file != NULL);
  SingleItem_descriptor_ = file->message_type(0);
  static const int SingleItem_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SingleItem, item_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SingleItem, num_),
  };
  SingleItem_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      SingleItem_descriptor_,
      SingleItem::default_instance_,
      SingleItem_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SingleItem, _has_bits_[0]),
      -1,
      -1,
      sizeof(SingleItem),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SingleItem, _internal_metadata_),
      -1);
  index_msg_descriptor_ = file->message_type(1);
  static const int index_msg_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(index_msg, max_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(index_msg, single_item_),
  };
  index_msg_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      index_msg_descriptor_,
      index_msg::default_instance_,
      index_msg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(index_msg, _has_bits_[0]),
      -1,
      -1,
      sizeof(index_msg),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(index_msg, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_index_5fmsg_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      SingleItem_descriptor_, &SingleItem::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      index_msg_descriptor_, &index_msg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_index_5fmsg_2eproto() {
  delete SingleItem::default_instance_;
  delete SingleItem_reflection_;
  delete index_msg::default_instance_;
  delete index_msg_reflection_;
}

void protobuf_AddDesc_index_5fmsg_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017index_msg.proto\"\'\n\nSingleItem\022\014\n\004item\030"
    "\001 \002(\014\022\013\n\003num\030\002 \001(\r\"=\n\tindex_msg\022\016\n\006max_i"
    "d\030\001 \002(\004\022 \n\013single_item\030\002 \003(\0132\013.SingleIte"
    "m", 121);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "index_msg.proto", &protobuf_RegisterTypes);
  SingleItem::default_instance_ = new SingleItem();
  index_msg::default_instance_ = new index_msg();
  SingleItem::default_instance_->InitAsDefaultInstance();
  index_msg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_index_5fmsg_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_index_5fmsg_2eproto {
  StaticDescriptorInitializer_index_5fmsg_2eproto() {
    protobuf_AddDesc_index_5fmsg_2eproto();
  }
} static_descriptor_initializer_index_5fmsg_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int SingleItem::kItemFieldNumber;
const int SingleItem::kNumFieldNumber;
#endif  // !_MSC_VER

SingleItem::SingleItem()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:SingleItem)
}

void SingleItem::InitAsDefaultInstance() {
}

SingleItem::SingleItem(const SingleItem& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:SingleItem)
}

void SingleItem::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  item_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  num_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SingleItem::~SingleItem() {
  // @@protoc_insertion_point(destructor:SingleItem)
  SharedDtor();
}

void SingleItem::SharedDtor() {
  item_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void SingleItem::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SingleItem::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SingleItem_descriptor_;
}

const SingleItem& SingleItem::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_index_5fmsg_2eproto();
  return *default_instance_;
}

SingleItem* SingleItem::default_instance_ = NULL;

SingleItem* SingleItem::New(::google::protobuf::Arena* arena) const {
  SingleItem* n = new SingleItem;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void SingleItem::Clear() {
  if (_has_bits_[0 / 32] & 3u) {
    if (has_item()) {
      item_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    }
    num_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool SingleItem::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SingleItem)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required bytes item = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_item()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_num;
        break;
      }

      // optional uint32 num = 2;
      case 2: {
        if (tag == 16) {
         parse_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &num_)));
          set_has_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SingleItem)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SingleItem)
  return false;
#undef DO_
}

void SingleItem::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SingleItem)
  // required bytes item = 1;
  if (has_item()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->item(), output);
  }

  // optional uint32 num = 2;
  if (has_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->num(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:SingleItem)
}

::google::protobuf::uint8* SingleItem::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:SingleItem)
  // required bytes item = 1;
  if (has_item()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->item(), target);
  }

  // optional uint32 num = 2;
  if (has_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->num(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SingleItem)
  return target;
}

int SingleItem::ByteSize() const {
  int total_size = 0;

  // required bytes item = 1;
  if (has_item()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->item());
  }
  // optional uint32 num = 2;
  if (has_num()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->num());
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SingleItem::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const SingleItem* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const SingleItem>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SingleItem::MergeFrom(const SingleItem& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_item()) {
      set_has_item();
      item_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.item_);
    }
    if (from.has_num()) {
      set_num(from.num());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void SingleItem::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SingleItem::CopyFrom(const SingleItem& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SingleItem::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void SingleItem::Swap(SingleItem* other) {
  if (other == this) return;
  InternalSwap(other);
}
void SingleItem::InternalSwap(SingleItem* other) {
  item_.Swap(&other->item_);
  std::swap(num_, other->num_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SingleItem::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SingleItem_descriptor_;
  metadata.reflection = SingleItem_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SingleItem

// required bytes item = 1;
bool SingleItem::has_item() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void SingleItem::set_has_item() {
  _has_bits_[0] |= 0x00000001u;
}
void SingleItem::clear_has_item() {
  _has_bits_[0] &= ~0x00000001u;
}
void SingleItem::clear_item() {
  item_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_item();
}
 const ::std::string& SingleItem::item() const {
  // @@protoc_insertion_point(field_get:SingleItem.item)
  return item_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void SingleItem::set_item(const ::std::string& value) {
  set_has_item();
  item_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SingleItem.item)
}
 void SingleItem::set_item(const char* value) {
  set_has_item();
  item_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SingleItem.item)
}
 void SingleItem::set_item(const void* value, size_t size) {
  set_has_item();
  item_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SingleItem.item)
}
 ::std::string* SingleItem::mutable_item() {
  set_has_item();
  // @@protoc_insertion_point(field_mutable:SingleItem.item)
  return item_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* SingleItem::release_item() {
  clear_has_item();
  return item_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void SingleItem::set_allocated_item(::std::string* item) {
  if (item != NULL) {
    set_has_item();
  } else {
    clear_has_item();
  }
  item_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), item);
  // @@protoc_insertion_point(field_set_allocated:SingleItem.item)
}

// optional uint32 num = 2;
bool SingleItem::has_num() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void SingleItem::set_has_num() {
  _has_bits_[0] |= 0x00000002u;
}
void SingleItem::clear_has_num() {
  _has_bits_[0] &= ~0x00000002u;
}
void SingleItem::clear_num() {
  num_ = 0u;
  clear_has_num();
}
 ::google::protobuf::uint32 SingleItem::num() const {
  // @@protoc_insertion_point(field_get:SingleItem.num)
  return num_;
}
 void SingleItem::set_num(::google::protobuf::uint32 value) {
  set_has_num();
  num_ = value;
  // @@protoc_insertion_point(field_set:SingleItem.num)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#ifndef _MSC_VER
const int index_msg::kMaxIdFieldNumber;
const int index_msg::kSingleItemFieldNumber;
#endif  // !_MSC_VER

index_msg::index_msg()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:index_msg)
}

void index_msg::InitAsDefaultInstance() {
}

index_msg::index_msg(const index_msg& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:index_msg)
}

void index_msg::SharedCtor() {
  _cached_size_ = 0;
  max_id_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

index_msg::~index_msg() {
  // @@protoc_insertion_point(destructor:index_msg)
  SharedDtor();
}

void index_msg::SharedDtor() {
  if (this != default_instance_) {
  }
}

void index_msg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* index_msg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return index_msg_descriptor_;
}

const index_msg& index_msg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_index_5fmsg_2eproto();
  return *default_instance_;
}

index_msg* index_msg::default_instance_ = NULL;

index_msg* index_msg::New(::google::protobuf::Arena* arena) const {
  index_msg* n = new index_msg;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void index_msg::Clear() {
  max_id_ = GOOGLE_ULONGLONG(0);
  single_item_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool index_msg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:index_msg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 max_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &max_id_)));
          set_has_max_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_single_item;
        break;
      }

      // repeated .SingleItem single_item = 2;
      case 2: {
        if (tag == 18) {
         parse_single_item:
          DO_(input->IncrementRecursionDepth());
         parse_loop_single_item:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_single_item()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_single_item;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:index_msg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:index_msg)
  return false;
#undef DO_
}

void index_msg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:index_msg)
  // required uint64 max_id = 1;
  if (has_max_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->max_id(), output);
  }

  // repeated .SingleItem single_item = 2;
  for (unsigned int i = 0, n = this->single_item_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->single_item(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:index_msg)
}

::google::protobuf::uint8* index_msg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:index_msg)
  // required uint64 max_id = 1;
  if (has_max_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->max_id(), target);
  }

  // repeated .SingleItem single_item = 2;
  for (unsigned int i = 0, n = this->single_item_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->single_item(i), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:index_msg)
  return target;
}

int index_msg::ByteSize() const {
  int total_size = 0;

  // required uint64 max_id = 1;
  if (has_max_id()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt64Size(
        this->max_id());
  }
  // repeated .SingleItem single_item = 2;
  total_size += 1 * this->single_item_size();
  for (int i = 0; i < this->single_item_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->single_item(i));
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void index_msg::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const index_msg* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const index_msg>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void index_msg::MergeFrom(const index_msg& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  single_item_.MergeFrom(from.single_item_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_max_id()) {
      set_max_id(from.max_id());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void index_msg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void index_msg::CopyFrom(const index_msg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool index_msg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (!::google::protobuf::internal::AllAreInitialized(this->single_item())) return false;
  return true;
}

void index_msg::Swap(index_msg* other) {
  if (other == this) return;
  InternalSwap(other);
}
void index_msg::InternalSwap(index_msg* other) {
  std::swap(max_id_, other->max_id_);
  single_item_.UnsafeArenaSwap(&other->single_item_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata index_msg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = index_msg_descriptor_;
  metadata.reflection = index_msg_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// index_msg

// required uint64 max_id = 1;
bool index_msg::has_max_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void index_msg::set_has_max_id() {
  _has_bits_[0] |= 0x00000001u;
}
void index_msg::clear_has_max_id() {
  _has_bits_[0] &= ~0x00000001u;
}
void index_msg::clear_max_id() {
  max_id_ = GOOGLE_ULONGLONG(0);
  clear_has_max_id();
}
 ::google::protobuf::uint64 index_msg::max_id() const {
  // @@protoc_insertion_point(field_get:index_msg.max_id)
  return max_id_;
}
 void index_msg::set_max_id(::google::protobuf::uint64 value) {
  set_has_max_id();
  max_id_ = value;
  // @@protoc_insertion_point(field_set:index_msg.max_id)
}

// repeated .SingleItem single_item = 2;
int index_msg::single_item_size() const {
  return single_item_.size();
}
void index_msg::clear_single_item() {
  single_item_.Clear();
}
 const ::SingleItem& index_msg::single_item(int index) const {
  // @@protoc_insertion_point(field_get:index_msg.single_item)
  return single_item_.Get(index);
}
 ::SingleItem* index_msg::mutable_single_item(int index) {
  // @@protoc_insertion_point(field_mutable:index_msg.single_item)
  return single_item_.Mutable(index);
}
 ::SingleItem* index_msg::add_single_item() {
  // @@protoc_insertion_point(field_add:index_msg.single_item)
  return single_item_.Add();
}
 const ::google::protobuf::RepeatedPtrField< ::SingleItem >&
index_msg::single_item() const {
  // @@protoc_insertion_point(field_list:index_msg.single_item)
  return single_item_;
}
 ::google::protobuf::RepeatedPtrField< ::SingleItem >*
index_msg::mutable_single_item() {
  // @@protoc_insertion_point(field_mutable_list:index_msg.single_item)
  return &single_item_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)