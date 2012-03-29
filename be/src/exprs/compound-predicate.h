// Copyright (c) 2011 Cloudera, Inc. All rights reserved.

#ifndef IMPALA_EXPRS_COMPOUND_PREDICATE_H_
#define IMPALA_EXPRS_COMPOUND_PREDICATE_H_

#include <string>
#include "exprs/predicate.h"
#include "gen-cpp/Exprs_types.h"

namespace impala {

class CompoundPredicate: public Predicate {
 public:
  virtual llvm::Function* Codegen(LlvmCodeGen* codegen);

 protected:
  friend class Expr;

  CompoundPredicate(const TExprNode& node);

  virtual Status Prepare(RuntimeState* state, const RowDescriptor& desc);
  virtual std::string DebugString() const;

 private:
  friend class OpcodeRegistry;

  static void* AndComputeFunction(Expr* e, TupleRow* row);
  static void* OrComputeFunction(Expr* e, TupleRow* row);
  static void* NotComputeFunction(Expr* e, TupleRow* row);
};

}

#endif
