#include "compiler.hpp"

#pragma warning(push, 0)
#include <experimental/filesystem>

#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/tools/bugpoint/ToolRunner.h"
#pragma warning(pop)

#include "utf.hpp"
#include "utils.hpp"

#include "errors.hpp"
#include "grammar.hpp"
#include "module.hpp"
#include "natural_value.hpp"
#include "scope.hpp"
#include "symbol.hpp"



using namespace std::experimental::filesystem;

namespace plc {

std::shared_ptr<analytic_value> do_concrete_invoke(llvm::Function * function, std::vector<llvm::Value *> arguments, scope & parent, llvm::BasicBlock * unwindDest, llvm::IRBuilder<> & builder) {
	ERROR(NotImplemented, "");
	/*auto nextBlock = llvm::BasicBlock::Create(llvmContext, "", &parent.getLLVMFunction(), nullptr);
	auto result = std::static_pointer_cast<analytic_value>(std::make_shared<natural_value>(builder.CreateInvoke(function, nextBlock, unwindDest, arguments, "")));
	builder.SetInsertPoint(nextBlock);
	return result;*/
}

std::shared_ptr<analytic_value> eval_expression(source_code const & source, std::vector<parlex::detail::match> const & parts, scope & parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder);

std::shared_ptr<analytic_value> eval_parenthetical_invocation(source_code const & source, std::vector<parlex::detail::match> const & parts, scope & parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
	ERROR(NotImplemented, "");
	/*
	std::vector<llvm::Value *> arguments;
	auto func = eval_expression(source, source.get_parts(parts[0]), parent, unwindDest, builder)->collapse();
	if (!func) {
	ERROR(NotImplemented, describe_code_span(source, parts[0]) + "Non-concrete function invocations are not implemented.");
	}
	auto llvmFunc = dynamic_cast<llvm::Function *>(func->underlying.get());
	if (!llvmFunc) {
	ERROR(ExpressionIsNotAFunction, source.pathname + describe_code_span(source, parts[0]));
	}

	for (size_t i = 1; i < parts.size(); ++i) { //0 is the function to invoke
	if (parts[i].r.name == "EXPRESSION") {
	auto argument = eval_expression(source, source.get_parts(parts[i]), parent, unwindDest, builder)->collapse();
	if (!argument) {
	ERROR(UnsupportedBootstrapFunctionality, "non-concrete function arguments are not available");
	}
	arguments.push_back(argument->underlying.get());
	}
	}
	return do_concrete_invoke(llvmFunc, arguments, parent, &unwindDest, builder);*/
}

// std::shared_ptr<analytic_value> eval_invocation(source_code const& source, std::vector<parlex::detail::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
// 	auto expressionType = &parts[0].r;
// 	if (expressionType == &PARENTHETICAL_INVOCATION) {
// 		return eval_parenthetical_invocation(source, source.get_parts(parts[0]), parent, unwindDest, builder);
// 	}
// 	ERROR(NotImplemented, "");
// }
// 
// std::shared_ptr<analytic_value> eval_identifier(const source_code& source, const std::u32string& name, const scope& parent, const llvm::BasicBlock & unwindDest, const llvm::IRBuilder<>& builder) {
// 	auto i = parent.symbols.find(name);
// 	if (i == parent.symbols.end()) {
// 		ERROR(UnknownSymbol, to_utf8(name));
// 	}
// 	return i->second.value;
// }
// 
// std::shared_ptr<analytic_value> eval_expression(source_code const& source, std::vector<parlex::detail::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
// 	auto expressionType = &parts[0].r;
// 
// 	if (expressionType == &ALLOCATION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &ARRAY) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &ASM_FUNCTION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &BINARY_OP) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &BOOL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &CAST) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &CEILING) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &COMPLEMENT) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &CONDITIONAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &DELTA) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &DIMENSIONAL_NUMBER) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &EMBEDDED_STRING) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &EQUALITY_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &FACTORIAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &FLOOR) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &FUNCTION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &GREATER_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &IDENTIFIER) {
// 		return eval_identifier(source, source.get_text(parts[0]), parent, unwindDest, builder);
// 	} else if (expressionType == &IF) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &INVOCATION) {
// 		return eval_invocation(source, source.get_parts(parts[0]), parent, unwindDest, builder);
// 	} else if (expressionType == &LESSER_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &LIST) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &MAGNITUDE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &MAP) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &MEMBER_ACCESS) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &NEAREST_INTEGER) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &NON_NEG_NUMBER) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &PARENTHETICAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &RADICAL) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &RANGE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SET) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SET_COMPREHENSION) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &STRING) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SUBSET_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &SUPERSET_CHAIN) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &TUPLE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &TYPE) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &UNARY_OP) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (expressionType == &VECTOR_NORM) {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.name == "null") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.name == "this") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.name == "this_func") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else if (parts[0].r.name == "this_type") {
// 		ERROR(NotImplemented, "expression not implemented");
// 	} else {
// 		ERROR(Unknown, "invalid expression type " + expressionType->name);
// 	}
// }
// 
// void eval_statement(source_code const& source, std::vector<parlex::detail::match> const& parts, scope& parent, llvm::BasicBlock & unwindDest, llvm::IRBuilder<> & builder) {
// 	ERROR(NotImplemented, "");
// /*
// 	auto p = parts[0];
// 	if (&p.r == &ASSIGNMENT_CHAIN) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &DEFINITION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &DO) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &EXPRESSION) {
// 		auto expression_value = eval_expression(source, source.get_parts(p), parent, unwindDest, builder);
// 		auto concrete = expression_value->collapse();
// 		if (!concrete) {
// 			ERROR(NotImplemented, "Non-concrete statement-scope expressions are not implemented.");
// 		}
// 		auto asFunc = dynamic_cast<llvm::Function *>(concrete->underlying.get());
// 		if (asFunc) {
// 			auto funcType = asFunc->getFunctionType();
// 			if (funcType->getNumParams() == 0 && funcType->getReturnType()->isVoidTy()) {
// 				do_concrete_invoke(asFunc, std::vector<llvm::Value *>(), parent, &unwindDest, builder);
// 			}
// 		}
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &FOR) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &FOR_COLLECTION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &FREE) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &IMPORT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &LOOP) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &RETURN) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &THROW) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &TRY) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (&p.r == &TYPE_CONSTRAINT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (p.r.name == "break") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else if (p.r.name == "continue") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	} else {
// 		ERROR(Unknown, "invalid statement type " + p.r.name);
// 	}
// */
// }

//symbol_table flatten_symbol_tables(symbol_table const & parent, symbol_table const & child) {
//	symbol_table results;
//	for (auto const & i : parent) {
//		auto const emplaceResult = results.emplace(i.first, i.second.delocalize()).second;
//		throw_assert(emplaceResult);
//	}
//	for (auto symbol : child) {
//		auto const i = results.find(symbol.first);
//		if (i == results.end()) {
//			results.emplace(symbol.first, symbol.second);
//		} else {
//			if (!!i->second.get_value() && symbol.second.get_is_variable()) {
//				ERROR(CannotAssignToConstant, to_utf8(symbol.first));
//			}
//			if (!!symbol.second.get_value()) {
//				ERROR(RedefinitionOfSymbol, to_utf8(symbol.first));
//			}
//		}
//	}
//	return results;
//}

// symbol_table compute_assignment_chain_symbol_table(source_code const& source, std::vector<parlex::detail::match> const& parts) {
// 	symbol_table results;
// 	for (auto const & part : parts) {
// 		if (&part.r == &IDENTIFIER) {
// 			std::u32string name = source.get_text(part);
// 			auto emplaceResult = results.emplace(name, symbol(name, nullptr, true, true)).second;
// 			throw_assert(emplaceResult);
// 		}
// 	}
// 	return results;
// }
//
// symbol compute_definition_symbol(source_code const& source, std::vector<parlex::detail::match> const& parts, scope & parent, llvm::BasicBlock & unwindBlock, llvm::IRBuilder<> & builder) {
// 	std::u32string name;
// 	std::shared_ptr<analytic_value> value;
// 	for (auto const & part : parts) {
// 		if (&part.r == &IDENTIFIER) {
// 			name = source.get_text(part);
// 		} else if (&part.r == &EXPRESSION) {
// 			value = eval_expression(source, source.get_parts(part), parent, unwindBlock, builder);
// 		}
// 	}
// 	ERROR(NotImplemented, "");
// }
// 
// symbol_table compute_statement_symbol_table(source_code const& source, std::vector<parlex::detail::match> const& parts, scope & parent, llvm::BasicBlock & unwindBlock, llvm::IRBuilder<> & builder) {
// 	auto p = parts[0];
// 	if (&p.r == &ASSIGNMENT_CHAIN) {
// 		return compute_assignment_chain_symbol_table(source, source.get_parts(p));
// 	}
// 	if (&p.r == &DEFINITION) {
// 		symbol_table results;
// 		auto result = compute_definition_symbol(source, source.get_parts(p), parent, unwindBlock, builder);
// 		results.insert(make_pair(result.name, result));
// 		return results;
// 	}
// 	if (&p.r == &DO) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &EXPRESSION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &FOR) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &FOR_COLLECTION) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &FREE) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &IMPORT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &LOOP) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &RETURN) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &THROW) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &TRY) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (&p.r == &TYPE_CONSTRAINT) {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (p.r.name == "break") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	if (p.r.name == "continue") {
// 		ERROR(NotImplemented, "statement not implemented");
// 	}
// 	ERROR(Unknown, "invalid statement type " + p.r.name);
// }
// 
// symbol_table compute_scope_symbol_table(source_code const& source, std::vector<parlex::detail::match> const& parts, scope& parent, llvm::BasicBlock & unwindBlock, llvm::IRBuilder<> & builder) {
// 	symbol_table results;
// 	for (auto part : parts) {
// 		if (&part.r == &STATEMENT) {
// 			symbol_table ofStatement = compute_statement_symbol_table(source, source.get_parts(part), parent, unwindBlock, builder);
// 		}
// 	}
// 	return flatten_symbol_tables(parent.symbols, results);
// }

std::shared_ptr<analytic_value> eval_statement_scope(source_code const & source, std::vector<parlex::detail::match> const & parts, scope & parent, llvm::BasicBlock & unwindBlock) {
	ERROR(NotImplemented, "");
	/*
	auto result = std::make_shared<scope>(source, parent);
	auto entryPointBlock = llvm::BasicBlock::Create(llvmContext, "", &parent.getLLVMFunction());
	llvm::IRBuilder<> scopeBuilder(entryPointBlock);
	for (auto part : parts) {
		if (&part.r == &STATEMENT) {
			eval_statement(source, source.get_parts(part), *result, unwindBlock, scopeBuilder);
		}
	}
	return result;*/
}

void compile(std::vector<std::reference_wrapper<source_code const>> sources) {
	/*
	std::vector<llvm::Type*> mainFuncArgTypes = {
		llvm::Type::getInt32Ty(llvmContext),
		llvm::Type::getInt8PtrTy(llvmContext)->getPointerTo()
	};

	auto mainFuncType = llvm::FunctionType::get(
		llvm::Type::getInt32Ty(llvmContext),
		mainFuncArgTypes,
		false
	);

	llvm::Function * mainFunc = llvm::Function::Create(mainFuncType, llvm::Function::ExternalLinkage, "main", &module);
	scope rootScope(mainFunc);
	llvm::IRBuilder<> builder(llvmContext);

	auto unwindBlock = llvm::BasicBlock::Create(llvmContext, "unwind", mainFunc);
	builder.SetInsertPoint(unwindBlock);
	builder.CreateLandingPad(llvm::Type::getVoidTy(llvmContext), 0);

	auto entryPointBlock = llvm::BasicBlock::Create(llvmContext, "entry_point", mainFunc);
	builder.SetInsertPoint(entryPointBlock);

	for (auto source : sources) {
		eval_statement_scope(source.get(), source.get().get_parts(source.get().asg.root), rootScope, *unwindBlock);
	}
	*/

}

STATEMENT_SCOPE compiler::parse(std::u32string const & source) {
	return source_code::parse(source);
}

void compiler::build_impl(std::string const & outputFilename, std::set<std::string> const & inputFiles) {
	std::map<std::string, module> modules;
	for (auto const & inputFile : inputFiles) {
		auto s = make_val<source_code const>(inputFile);
		auto & module = modules.emplace(std::piecewise_construct, std::forward_as_tuple(inputFile), std::forward_as_tuple(*this, s)).first->second;
		inject_std_lib(module);
		ERROR(NotImplemented, "");
	}
}

void compiler::build(std::string const & outputFilename, std::set<std::string> const & inputFiles) {
	compiler c;
	c.build_impl(outputFilename, inputFiles);
}

static void init_llvm() {
	static std::once_flag llvmInit;

	std::call_once(llvmInit, []
	{
		llvm::InitializeAllTargetInfos();
		llvm::InitializeAllTargets();
		llvm::InitializeAllTargetMCs();
		llvm::InitializeAllAsmParsers();
		llvm::InitializeAllAsmPrinters();
	});
}

static std::string get_default_target_triple() {
	init_llvm();
	return llvm::sys::getDefaultTargetTriple();
}

static llvm::TargetMachine * get_default_target_machine() {
	init_llvm();
	auto const targetTriple = get_default_target_triple();
	std::string error;
	auto const target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

	if (!target) {
		ERROR(Unknown, error);
	}

	auto const cpu = "generic";
	auto const features = "";
	llvm::TargetOptions const opt;
	auto const rm = llvm::Optional<llvm::Reloc::Model>();
	return target->createTargetMachine(targetTriple, cpu, features, opt, rm);
}

compiler::compiler() : target_triple_(get_default_target_triple()), target_machine_(get_default_target_machine()) {}

llvm::LLVMContext & compiler::get_llvm_context()
{
	return llvm_context_;
}

llvm::TargetMachine & compiler::get_target_machine() {
	return *target_machine_;
}

// The ._pg extension ensures that parent namespaces are alphabetically sorted before their children
std::set<std::string> enumerate_std_lib_sources() {
	std::set<std::string> results;
	auto const rootPath = canonical(path(__FILE__).remove_filename().append("/../../stdlib"));
	for (auto const & entry : recursive_directory_iterator(rootPath)) {
		if (is_regular_file(entry)) {
			path entryPath(entry);
			// todo: remove this filter to load the whole standard library
			if (entryPath.filename() == "Plange.CStdLib._pg" || entryPath.filename() == "Plange.CStdLib.Generated._pg") {
				results.insert(entryPath.string());
			}
		}
	}
	return results;
}

static std::list<std::u32string> namespace_string_to_namespaces(std::u32string namespaceString) {
	replace(namespaceString.begin(), namespaceString.end(), '.', '\n'); // replace '.' by ' '
	std::list<std::u32string> result;
	std::basic_istringstream<char32_t> in(namespaceString);
	std::u32string line;
	while (getline(in, line)) {
		result.push_back(line);
	}
	return result;
}

void compiler::inject_std_lib(module & m) {
	for (auto const & filename : enumerate_std_lib_sources()) {
		auto const ext = path(filename).extension().string();
		if (ext == "._pg") {
			// file is a namespace
			auto sourceCode = make_val<source_code>(filename);
			auto namespaceNames(namespace_string_to_namespaces(to_utf32(path(filename).stem().string())));
			throw_assert(namespaceNames.front() == U"Plange");
			namespaceNames.pop_front();
			ptr<scope> currentScope = m.plange;
			std::optional<ptr<scope>> parentScope = std::nullopt;
			for (auto i = namespaceNames.begin(); i != namespaceNames.end(); ++i) {
				std::u32string namespaceName = *i;
				auto k = i;
				++k;
				auto const isNamespaceOfFile = k == namespaceNames.end();
				auto j = currentScope->symbols.find(*i);
				if (j == currentScope->symbols.end()) {
					// namespace not yet created
					ptr<source_code const> a = sourceCode;
					val<scope> newScope = make_val<scope>(m, isNamespaceOfFile ? nptr<source_code const>(a) : std::nullopt, parentScope);
					scope::load_dom(newScope, sourceCode->get_representation());
					symbol s(
						namespaceName,
						*newScope,
						std::nullopt,
						*parentScope,
						true,
						true,
						U"",
						{},
						visibility::PUBLIC,
						false,
						false,
						false
					);
					currentScope->symbols.emplace(std::piecewise_construct, make_tuple(namespaceName), std::make_tuple(s));
					parentScope = currentScope;
					currentScope = newScope;
				} else {
					// symbol already exists
					throw_assert(!isNamespaceOfFile); // This filename represents this scope. Make sure the scope is not already created.
					std::optional<val<analytic_value>> a = j->second->get_value();
					if (a.has_value()) {
						parentScope = currentScope;
						currentScope = ptr<scope const>(*a);
						
					} else {
						ERROR(NotImplemented, "");
					}
				}
			}
			if (namespaceNames == std::list<std::u32string>{U"Plange", U"CStdLib", U"Generated"}) {
				// We need not only standard handling, but also to treat these a c declarations
				ERROR(NotImplemented, "");
			}
		} else if (ext == ".pgo") {
			// file is an object literal
			ERROR(NotImplemented, "");
		} else if (ext == ".pge") {
			// file is regular code
			ERROR(NotImplemented, "");
		} else {
			ERROR(UnexpectedStandardLibraryFileExtension, filename);
			// ignore unrecognized file extensions
		}
	}
}

}
