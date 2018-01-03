#include "compiler.hpp"

#include <fstream>
#include <experimental/filesystem>

#include <gtest/gtest.h>

#include "EXPRESSION.hpp"
#include "TYPE_CONSTRAINT.hpp"
#include "STATEMENT.hpp"
#include "MAPS_TO.hpp"
#include "MULTIPLICATION.hpp"
#include "BINARY_OP.hpp"
#include "BINARY_LOGICAL_OP.hpp"

#include "module.hpp"
#include "utf.hpp"
#include "errors.hpp"
#include "parlex/detail/parser.hpp"

static std::string const & stdlibs_dir() {
	static auto result = to_utf8(canonical(std::experimental::filesystem::path(__FILE__).remove_filename().append("/../../stdlib/"))) + std::string("/");
	return result;
}

static std::string const & examples_dir() {
	static auto result = to_utf8(canonical(std::experimental::filesystem::path(__FILE__).remove_filename().append("/../../../examples/"))) + std::string("/");
	return result;
}

TEST(PlcCompiler, ParseTupleMapsToExpression) {
	auto result = plc::compiler::parse<plc::MAPS_TO>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsTo) {
	auto result = plc::compiler::parse<plc::MULTIPLICATION>(U"a*b->c");
}

TEST(PlcCompiler, ParseMultiplyMapsToExpression) {
	auto result = plc::compiler::parse<plc::EXPRESSION>(U"a*b->c");
	ASSERT_TRUE(std::holds_alternative<erased<plc::BINARY_OP>>(result));
	plc::BINARY_OP const & binaryOp = *std::get<erased<plc::BINARY_OP>>(result);
	ASSERT_TRUE(std::holds_alternative<erased<plc::BINARY_LOGICAL_OP>>(binaryOp));
	plc::BINARY_LOGICAL_OP const & binaryLogicalOp = *std::get<erased<plc::BINARY_LOGICAL_OP>>(binaryOp);
	ASSERT_TRUE(std::holds_alternative<erased<plc::MAPS_TO>>(binaryLogicalOp));
}

TEST(PlcCompiler, ParseTypeConstraint) {
	auto result = plc::compiler::parse<plc::TYPE_CONSTRAINT>(U"<a> b");
}

TEST(PlcCompiler, ParseBinaryFunctionTypeConstraint) {
	auto result = plc::compiler::parse<plc::TYPE_CONSTRAINT>(U"<a * b -> c> d");
}

TEST(PlcCompiler, ParseExternBinaryFunctionTypeConstraint) {
	auto result = plc::compiler::parse<plc::TYPE_CONSTRAINT>(U"extern <a * b -> c> d");
}
 
TEST(PlcCompiler, ParseExternBinaryFunctionTypeConstraintStatement) {
	auto result = plc::compiler::parse<plc::STATEMENT>(U"extern <a * b -> c> d;");
}

TEST(PlcCompiler, ParseCompound) {
	auto result = plc::compiler::parse<plc::EXPRESSION>(U"a|b|c");
}

TEST(PlcCompiler, ParseHelloWorld) {
	auto result = plc::compiler::parse(U"print(\"Hello, world!\");");
}

TEST(PlcCompiler, ParseType) {
	auto const source = U"myType := type {"
		"    public <Int> aVariable;"
		"};"
		"";
	auto result = plc::compiler::parse(source);
}

TEST(PlcCompiler, ParseFILEPointer) {
	auto const source = U"FILEPointer := type_abstraction(Pointer<Void>);\n";
	auto result = plc::compiler::parse(source);
}

TEST(PlcCompiler, ParsePrintHelloWorld) {
	auto const source = U"print(\"Hello, world!\");";
	plc::source_code("", source);
}

static std::u32string read(std::string const & filePathname) {
	std::ifstream ifs(filePathname, std::ios::binary);
	if (!ifs) {
		ERROR(CouldNotOpenFile, filePathname);
	}
	return read_with_bom(move(ifs));
}

TEST(PlcCompiler, ParseCStdLibGenerated) {
	auto const filePathname = stdlibs_dir() + "Plange.CStdLib.Generated._pg";
	static parlex::detail::parser p;
	auto & g = plc::plange_grammar::get();
	auto & main = g.get_recognizer(plc::plange_grammar::get().STATEMENT_SCOPE);
	auto const document = read(filePathname);
	auto assl = p.parse(g, main, document);
	EXPECT_TRUE(assl.is_rooted());
}

TEST(PlcCompiler, LoadCStdLibGenerated) {
	auto const filePathname = stdlibs_dir() + "Plange.CStdLib.Generated._pg";
	auto result = plc::source_code(filePathname);
}

static void parse_example(std::string const & exampleName) {
	auto const filePathname = examples_dir() + exampleName;
	static parlex::detail::parser p;
	auto const & statementScopeRecognizer = plc::plange_grammar::get().get_recognizer(plc::plange_grammar::get().STATEMENT_SCOPE);
	auto assl = p.parse(plc::plange_grammar::get(), statementScopeRecognizer, read(filePathname));
	EXPECT_TRUE(assl.is_rooted());
}

static void load_example(std::string const & exampleName) {
	auto const filePathname = examples_dir() + exampleName;
	auto result = plc::source_code(filePathname);
}

TEST(PlcCompiler, ParseEmbeddedCommentExample) {
	parse_example("embeddedComment.pge");
}

TEST(PlcCompiler, LoadEmbeddedCommentExample) {
	load_example("embeddedComment.pge");
}