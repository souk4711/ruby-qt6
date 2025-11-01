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
            .define_method("to_string", &QKeySequence::toString, Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            // Static Public Members
            .define_singleton_function("from_string", &QKeySequence::fromString, Arg("str"), Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            .define_singleton_function("key_bindings", &QKeySequence::keyBindings, Arg("key"))
            .define_singleton_function("list_from_string", &QKeySequence::listFromString, Arg("str"), Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            .define_singleton_function("list_to_string", &QKeySequence::listToString, Arg("list"), Arg("format") = static_cast<QKeySequence::SequenceFormat>(QKeySequence::SequenceFormat::PortableText))
            .define_singleton_function("mnemonic", &QKeySequence::mnemonic, Arg("text"));

    Data_Type<QKeySequence::SequenceFormat> rb_cQKeySequenceSequenceFormat =
        // RubyQt6::QtGui::QKeySequence::SequenceFormat
        define_qenum_under<QKeySequence::SequenceFormat>(rb_cQKeySequence, "SequenceFormat");
        define_qenum_value_under(rb_cQKeySequenceSequenceFormat, "NativeText", QKeySequence::SequenceFormat::NativeText);
        define_qenum_value_under(rb_cQKeySequenceSequenceFormat, "PortableText", QKeySequence::SequenceFormat::PortableText);

    Data_Type<QKeySequence::SequenceMatch> rb_cQKeySequenceSequenceMatch =
        // RubyQt6::QtGui::QKeySequence::SequenceMatch
        define_qenum_under<QKeySequence::SequenceMatch>(rb_cQKeySequence, "SequenceMatch");
        define_qenum_value_under(rb_cQKeySequenceSequenceMatch, "NoMatch", QKeySequence::SequenceMatch::NoMatch);
        define_qenum_value_under(rb_cQKeySequenceSequenceMatch, "PartialMatch", QKeySequence::SequenceMatch::PartialMatch);
        define_qenum_value_under(rb_cQKeySequenceSequenceMatch, "ExactMatch", QKeySequence::SequenceMatch::ExactMatch);

    Data_Type<QKeySequence::StandardKey> rb_cQKeySequenceStandardKey =
        // RubyQt6::QtGui::QKeySequence::StandardKey
        define_qenum_under<QKeySequence::StandardKey>(rb_cQKeySequence, "StandardKey");
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "UnknownKey", QKeySequence::StandardKey::UnknownKey);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "HelpContents", QKeySequence::StandardKey::HelpContents);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "WhatsThis", QKeySequence::StandardKey::WhatsThis);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Open", QKeySequence::StandardKey::Open);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Close", QKeySequence::StandardKey::Close);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Save", QKeySequence::StandardKey::Save);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "New", QKeySequence::StandardKey::New);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Delete", QKeySequence::StandardKey::Delete);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Cut", QKeySequence::StandardKey::Cut);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Copy", QKeySequence::StandardKey::Copy);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Paste", QKeySequence::StandardKey::Paste);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Undo", QKeySequence::StandardKey::Undo);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Redo", QKeySequence::StandardKey::Redo);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Back", QKeySequence::StandardKey::Back);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Forward", QKeySequence::StandardKey::Forward);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Refresh", QKeySequence::StandardKey::Refresh);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "ZoomIn", QKeySequence::StandardKey::ZoomIn);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "ZoomOut", QKeySequence::StandardKey::ZoomOut);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Print", QKeySequence::StandardKey::Print);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "AddTab", QKeySequence::StandardKey::AddTab);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "NextChild", QKeySequence::StandardKey::NextChild);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "PreviousChild", QKeySequence::StandardKey::PreviousChild);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Find", QKeySequence::StandardKey::Find);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "FindNext", QKeySequence::StandardKey::FindNext);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "FindPrevious", QKeySequence::StandardKey::FindPrevious);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Replace", QKeySequence::StandardKey::Replace);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectAll", QKeySequence::StandardKey::SelectAll);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Bold", QKeySequence::StandardKey::Bold);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Italic", QKeySequence::StandardKey::Italic);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Underline", QKeySequence::StandardKey::Underline);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToNextChar", QKeySequence::StandardKey::MoveToNextChar);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToPreviousChar", QKeySequence::StandardKey::MoveToPreviousChar);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToNextWord", QKeySequence::StandardKey::MoveToNextWord);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToPreviousWord", QKeySequence::StandardKey::MoveToPreviousWord);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToNextLine", QKeySequence::StandardKey::MoveToNextLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToPreviousLine", QKeySequence::StandardKey::MoveToPreviousLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToNextPage", QKeySequence::StandardKey::MoveToNextPage);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToPreviousPage", QKeySequence::StandardKey::MoveToPreviousPage);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToStartOfLine", QKeySequence::StandardKey::MoveToStartOfLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToEndOfLine", QKeySequence::StandardKey::MoveToEndOfLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToStartOfBlock", QKeySequence::StandardKey::MoveToStartOfBlock);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToEndOfBlock", QKeySequence::StandardKey::MoveToEndOfBlock);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToStartOfDocument", QKeySequence::StandardKey::MoveToStartOfDocument);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "MoveToEndOfDocument", QKeySequence::StandardKey::MoveToEndOfDocument);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectNextChar", QKeySequence::StandardKey::SelectNextChar);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectPreviousChar", QKeySequence::StandardKey::SelectPreviousChar);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectNextWord", QKeySequence::StandardKey::SelectNextWord);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectPreviousWord", QKeySequence::StandardKey::SelectPreviousWord);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectNextLine", QKeySequence::StandardKey::SelectNextLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectPreviousLine", QKeySequence::StandardKey::SelectPreviousLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectNextPage", QKeySequence::StandardKey::SelectNextPage);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectPreviousPage", QKeySequence::StandardKey::SelectPreviousPage);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectStartOfLine", QKeySequence::StandardKey::SelectStartOfLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectEndOfLine", QKeySequence::StandardKey::SelectEndOfLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectStartOfBlock", QKeySequence::StandardKey::SelectStartOfBlock);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectEndOfBlock", QKeySequence::StandardKey::SelectEndOfBlock);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectStartOfDocument", QKeySequence::StandardKey::SelectStartOfDocument);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SelectEndOfDocument", QKeySequence::StandardKey::SelectEndOfDocument);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "DeleteStartOfWord", QKeySequence::StandardKey::DeleteStartOfWord);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "DeleteEndOfWord", QKeySequence::StandardKey::DeleteEndOfWord);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "DeleteEndOfLine", QKeySequence::StandardKey::DeleteEndOfLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "InsertParagraphSeparator", QKeySequence::StandardKey::InsertParagraphSeparator);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "InsertLineSeparator", QKeySequence::StandardKey::InsertLineSeparator);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "SaveAs", QKeySequence::StandardKey::SaveAs);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Preferences", QKeySequence::StandardKey::Preferences);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Quit", QKeySequence::StandardKey::Quit);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "FullScreen", QKeySequence::StandardKey::FullScreen);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Deselect", QKeySequence::StandardKey::Deselect);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "DeleteCompleteLine", QKeySequence::StandardKey::DeleteCompleteLine);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Backspace", QKeySequence::StandardKey::Backspace);
        define_qenum_value_under(rb_cQKeySequenceStandardKey, "Cancel", QKeySequence::StandardKey::Cancel);
}
