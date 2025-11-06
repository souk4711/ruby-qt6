# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qtextdocument.html
    class QTextDocument < RubyQt6::QtCore::QObject
      # @!parse class FindFlag        ; end
      # @!parse class FindFlags       ; end
      # @!parse class MarkdownFeature ; end
      # @!parse class MarkdownFeatures; end
      # @!parse class MetaInformation ; end
      # @!parse class ResourceType    ; end
      # @!parse class Stacks          ; end
      rubyqt6_declare_enum_under QTextDocument, QTextDocument::FindFlag
      rubyqt6_declare_enum_under QTextDocument, QTextDocument::MarkdownFeature
      rubyqt6_declare_enum_under QTextDocument, QTextDocument::MetaInformation
      rubyqt6_declare_enum_under QTextDocument, QTextDocument::ResourceType
      rubyqt6_declare_enum_under QTextDocument, QTextDocument::Stacks
      rubyqt6_declare_qflags QTextDocument::FindFlags, QTextDocument::FindFlag
      rubyqt6_declare_qflags QTextDocument::MarkdownFeatures, QTextDocument::MarkdownFeature

      # @!parse
      q_object do
        signal "baseUrlChanged(QUrl)"
        signal "blockCountChanged(int)"
        signal "contentsChange(int,int,int)"
        signal "contentsChanged()"
        signal "cursorPositionChanged(QTextCursor)"
        signal "documentLayoutChanged()"
        signal "modificationChanged(bool)"
        signal "redoAvailable(bool)"
        signal "undoAvailable(bool)"
        signal "undoCommandAdded()"
        slot "redo()"
        slot "setModified(bool)"
        slot "setModified()"
        slot "undo()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [String, QString]
      # @param parent [QObject]
      # @return [QTextDocument]
      def initialize(text, parent = nil)
        _initialize(T.to_qstr(text), parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def find(*args)
        T.args_nth_to_qstr(args, 0)
        _find(*args)
      end
    end
  end
end
