// As of Visual Studio 2017 (15.5.1), xutility will emit warnings about LLVM code despite "#pragma warning(push, 0)" below
// This will silence those errors so we can build while treating warnings as errors
// ReSharper disable once CppInconsistentNaming
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING

#include "module.hpp"

#include <fstream>

#pragma warning(push, 0)
#include "llvm/IR/Constants.h"
#pragma warning(pop)


#include "compiler.hpp"
#include "errors.hpp"
#include "utf.hpp"

plc::module::module(compiler * owner) : owner(*owner), llvm_module("module", owner->llvm_context), plange(*this, nullptr, nullptr)
{
	throw_assert(owner);
}

void plc::module::compile(std::string output_filename) const
{
	ERROR(NotImplemented, "");
}

plc::source_code const & plc::module::add_source(std::string pathname) {
	sources.emplace_back(pathname);
	return sources.back();
}

llvm::Module const & plc::module::get_llvm_module() const
{
	return llvm_module;
}

llvm::Module & plc::module::get_llvm_module()
{
	return llvm_module;
}

llvm::GlobalVariable * plc::module::get_or_add_global_string(std::u32string const& s)
{
	auto const i = global_strings.find(s);
	if (i != global_strings.end()) return i->second;
	llvm::StringRef const str(to_utf8(s));
	auto const strConstant = llvm::ConstantDataArray::getString(owner.llvm_context, str);
	auto gv = new llvm::GlobalVariable(llvm_module, strConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, strConstant);
	auto const name = "str" + std::to_string(global_strings.size());
	gv->setName(name);
	//gv->setUnnamedAddr(true)
	return global_strings[s] = gv;
}
