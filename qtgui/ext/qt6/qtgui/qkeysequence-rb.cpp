#include "qkeysequence-rb.hpp"
#include <qkeysequence.h>
#include <rice/qenum.hpp>

#include <QList>

using namespace Rice;

Rice::Class rb_cQKeySequence;

void Init_qkeysequence(Rice::Module rb_mQt6QtGui)
{
    rb_cQKeySequence =
        // RubyQt6::QtGui::QKeySequence
        define_class_under<QKeySequence>(rb_mQt6QtGui, "QKeySequence")
            // Constructor
            .define_constructor(Constructor<QKeySequence>())
            .define_constructor(Constructor<QKeySequence, int>(), Arg("key"))
            .define_constructor(Constructor<QKeySequence, QKeySequence::StandardKey>(), Arg("key"))
            .define_constructor(Constructor<QKeySequence, const QString &>(), Arg("key"))
            // Public Functions
            .define_method("count", &QKeySequence::count)
            .define_method("detached?", &QKeySequence::isDetached)
            .define_method("empty?", &QKeySequence::isEmpty)
            .define_method("matches", &QKeySequence::matches, Arg("seq"))
            .define_method("swap", &QKeySequence::swap, Arg("other"))
            .define_method("to_string", &QKeySequence::toString, Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            // Static Public Members
            .define_singleton_function("from_string", &QKeySequence::fromString, Arg("str"), Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            .define_singleton_function("key_bindings", &QKeySequence::keyBindings, Arg("key"))
            .define_singleton_function("list_from_string", &QKeySequence::listFromString, Arg("str"), Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            .define_singleton_function("list_to_string", &QKeySequence::listToString, Arg("list"), Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            .define_singleton_function("mnemonic", &QKeySequence::mnemonic, Arg("text"));

    Enum<QKeySequence::SequenceFormat> rb_cQKeySequenceSequenceFormat =
        // RubyQt6::QtGui::QKeySequence::SequenceFormat
        define_qenum_under<QKeySequence::SequenceFormat>("SequenceFormat", rb_cQKeySequence)
            .define_value("NativeText", QKeySequence::SequenceFormat::NativeText)
            .define_value("PortableText", QKeySequence::SequenceFormat::PortableText);

    Enum<QKeySequence::SequenceMatch> rb_cQKeySequenceSequenceMatch =
        // RubyQt6::QtGui::QKeySequence::SequenceMatch
        define_qenum_under<QKeySequence::SequenceMatch>("SequenceMatch", rb_cQKeySequence)
            .define_value("NoMatch", QKeySequence::SequenceMatch::NoMatch)
            .define_value("PartialMatch", QKeySequence::SequenceMatch::PartialMatch)
            .define_value("ExactMatch", QKeySequence::SequenceMatch::ExactMatch);

    Enum<QKeySequence::StandardKey> rb_cQKeySequenceStandardKey =
        // RubyQt6::QtGui::QKeySequence::StandardKey
        define_qenum_under<QKeySequence::StandardKey>("StandardKey", rb_cQKeySequence)
            .define_value("UnknownKey", QKeySequence::StandardKey::UnknownKey)
            .define_value("HelpContents", QKeySequence::StandardKey::HelpContents)
            .define_value("WhatsThis", QKeySequence::StandardKey::WhatsThis)
            .define_value("Open", QKeySequence::StandardKey::Open)
            .define_value("Close", QKeySequence::StandardKey::Close)
            .define_value("Save", QKeySequence::StandardKey::Save)
            .define_value("New", QKeySequence::StandardKey::New)
            .define_value("Delete", QKeySequence::StandardKey::Delete)
            .define_value("Cut", QKeySequence::StandardKey::Cut)
            .define_value("Copy", QKeySequence::StandardKey::Copy)
            .define_value("Paste", QKeySequence::StandardKey::Paste)
            .define_value("Undo", QKeySequence::StandardKey::Undo)
            .define_value("Redo", QKeySequence::StandardKey::Redo)
            .define_value("Back", QKeySequence::StandardKey::Back)
            .define_value("Forward", QKeySequence::StandardKey::Forward)
            .define_value("Refresh", QKeySequence::StandardKey::Refresh)
            .define_value("ZoomIn", QKeySequence::StandardKey::ZoomIn)
            .define_value("ZoomOut", QKeySequence::StandardKey::ZoomOut)
            .define_value("Print", QKeySequence::StandardKey::Print)
            .define_value("AddTab", QKeySequence::StandardKey::AddTab)
            .define_value("NextChild", QKeySequence::StandardKey::NextChild)
            .define_value("PreviousChild", QKeySequence::StandardKey::PreviousChild)
            .define_value("Find", QKeySequence::StandardKey::Find)
            .define_value("FindNext", QKeySequence::StandardKey::FindNext)
            .define_value("FindPrevious", QKeySequence::StandardKey::FindPrevious)
            .define_value("Replace", QKeySequence::StandardKey::Replace)
            .define_value("SelectAll", QKeySequence::StandardKey::SelectAll)
            .define_value("Bold", QKeySequence::StandardKey::Bold)
            .define_value("Italic", QKeySequence::StandardKey::Italic)
            .define_value("Underline", QKeySequence::StandardKey::Underline)
            .define_value("MoveToNextChar", QKeySequence::StandardKey::MoveToNextChar)
            .define_value("MoveToPreviousChar", QKeySequence::StandardKey::MoveToPreviousChar)
            .define_value("MoveToNextWord", QKeySequence::StandardKey::MoveToNextWord)
            .define_value("MoveToPreviousWord", QKeySequence::StandardKey::MoveToPreviousWord)
            .define_value("MoveToNextLine", QKeySequence::StandardKey::MoveToNextLine)
            .define_value("MoveToPreviousLine", QKeySequence::StandardKey::MoveToPreviousLine)
            .define_value("MoveToNextPage", QKeySequence::StandardKey::MoveToNextPage)
            .define_value("MoveToPreviousPage", QKeySequence::StandardKey::MoveToPreviousPage)
            .define_value("MoveToStartOfLine", QKeySequence::StandardKey::MoveToStartOfLine)
            .define_value("MoveToEndOfLine", QKeySequence::StandardKey::MoveToEndOfLine)
            .define_value("MoveToStartOfBlock", QKeySequence::StandardKey::MoveToStartOfBlock)
            .define_value("MoveToEndOfBlock", QKeySequence::StandardKey::MoveToEndOfBlock)
            .define_value("MoveToStartOfDocument", QKeySequence::StandardKey::MoveToStartOfDocument)
            .define_value("MoveToEndOfDocument", QKeySequence::StandardKey::MoveToEndOfDocument)
            .define_value("SelectNextChar", QKeySequence::StandardKey::SelectNextChar)
            .define_value("SelectPreviousChar", QKeySequence::StandardKey::SelectPreviousChar)
            .define_value("SelectNextWord", QKeySequence::StandardKey::SelectNextWord)
            .define_value("SelectPreviousWord", QKeySequence::StandardKey::SelectPreviousWord)
            .define_value("SelectNextLine", QKeySequence::StandardKey::SelectNextLine)
            .define_value("SelectPreviousLine", QKeySequence::StandardKey::SelectPreviousLine)
            .define_value("SelectNextPage", QKeySequence::StandardKey::SelectNextPage)
            .define_value("SelectPreviousPage", QKeySequence::StandardKey::SelectPreviousPage)
            .define_value("SelectStartOfLine", QKeySequence::StandardKey::SelectStartOfLine)
            .define_value("SelectEndOfLine", QKeySequence::StandardKey::SelectEndOfLine)
            .define_value("SelectStartOfBlock", QKeySequence::StandardKey::SelectStartOfBlock)
            .define_value("SelectEndOfBlock", QKeySequence::StandardKey::SelectEndOfBlock)
            .define_value("SelectStartOfDocument", QKeySequence::StandardKey::SelectStartOfDocument)
            .define_value("SelectEndOfDocument", QKeySequence::StandardKey::SelectEndOfDocument)
            .define_value("DeleteStartOfWord", QKeySequence::StandardKey::DeleteStartOfWord)
            .define_value("DeleteEndOfWord", QKeySequence::StandardKey::DeleteEndOfWord)
            .define_value("DeleteEndOfLine", QKeySequence::StandardKey::DeleteEndOfLine)
            .define_value("InsertParagraphSeparator", QKeySequence::StandardKey::InsertParagraphSeparator)
            .define_value("InsertLineSeparator", QKeySequence::StandardKey::InsertLineSeparator)
            .define_value("SaveAs", QKeySequence::StandardKey::SaveAs)
            .define_value("Preferences", QKeySequence::StandardKey::Preferences)
            .define_value("Quit", QKeySequence::StandardKey::Quit)
            .define_value("FullScreen", QKeySequence::StandardKey::FullScreen)
            .define_value("Deselect", QKeySequence::StandardKey::Deselect)
            .define_value("DeleteCompleteLine", QKeySequence::StandardKey::DeleteCompleteLine)
            .define_value("Backspace", QKeySequence::StandardKey::Backspace)
            .define_value("Cancel", QKeySequence::StandardKey::Cancel);
}
