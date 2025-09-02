# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qlabel.html
    class QLabel < RubyQt6::QtWidgets::QFrame
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [QString]
      # @param parent [QWidget]
      # @return [QLabel]
      #
      # Constructs a label that displays the text.
      def initialize(text, parent = nil)
        _initialize(QtCore::QString.new(text), parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @return [Qt::Alignment]
      #
      # This property holds the alignment of the label's contents.
      #
      # By default, the contents of the label are left-aligned and
      # vertically-centered.
      def alignment
        _alignment
      end

      # @return [QWidget]
      #
      # Returns this label's buddy, or nullptr if no buddy is currently set.
      def buddy
        _buddy
      end

      # @return [Integer]
      #
      # This property holds the label's text indent in pixels.
      #
      # If a label displays text, the indent applies to the left edge if
      # alignment() is Qt::AlignLeft, to the right edge if alignment() is
      # Qt::AlignRight, to the top edge if alignment() is Qt::AlignTop, and
      # to the bottom edge if alignment() is Qt::AlignBottom.
      #
      # If indent is negative, or if no indent has been set, the label
      # computes the effective indent as follows: If frameWidth() is 0,
      # the effective indent becomes 0. If frameWidth() is greater than 0,
      # the effective indent becomes half the width of the "x" character
      # of the widget's current font().
      #
      # By default, the indent is -1, meaning that an effective indent is
      # calculating in the manner described above.
      def indent
        _indent
      end

      # @return [Integer]
      #
      # This property holds the width of the margin.
      #
      # The margin is the distance between the innermost pixel of the frame
      # and the outermost pixel of contents.
      #
      # The default margin is 0.
      def margin
        _margin
      end

      # @return [QMovie]
      #
      # Returns a pointer to the label's movie, or nullptr if no movie has
      # been set.
      def movie
        _movie
      end

      # @return [QPicture]
      #
      # Returns the label's picture.
      def picture
        _picture
      end

      # @return [QPixmap]
      #
      # This property holds the label's pixmap.
      #
      # Setting the pixmap clears any previous content. The buddy shortcut,
      # if any, is disabled.
      def pixmap
        _pixmap
      end

      # @return [QTextDocument::ResourceProvider]
      #
      # Returns the resource provider for rich text of this label.
      def resource_provider
        _resource_provider
      end

      # @return [QString]
      #
      # This property holds the selected text
      #
      # If there is no selected text this property's value is an empty string.
      #
      # By default, this property contains an empty string.
      #
      # Note: The textInteractionFlags set on the label need to include either
      # TextSelectableByMouse or TextSelectableByKeyboard.
      def selected_text
        _selected_text
      end

      # @return [Integer]
      #
      # selectionStart() returns the index of the first selected character in
      # the label or -1 if no text is selected.
      #
      # Note: The textInteractionFlags set on the label need to include either
      # TextSelectableByMouse or TextSelectableByKeyboard.
      def selection_start
        _selection_start
      end

      # @return [QString]
      #
      # This property holds the label's text.
      #
      # If no text has been set this will return an empty string. Setting the
      # text clears any previous content.
      #
      # The text will be interpreted either as plain text or as rich text,
      # depending on the text format setting; see setTextFormat(). The default
      # setting is Qt::AutoText; i.e. QLabel will try to auto-detect the
      # format of the text set. See Supported HTML Subset for the definition
      # of rich text.
      #
      # If a buddy has been set, the buddy mnemonic key is updated from the
      # new text.
      #
      # Note that QLabel is well-suited to display small rich text documents,
      # such as small documents that get their document specific settings
      # (font, text color, link color) from the label's palette and font
      # properties. For large documents, use QTextEdit in read-only mode
      # instead. QTextEdit can also provide a scroll bar when necessary.
      def text
        _text
      end

      # @return [Qt::TextFormat]
      #
      # This property holds the label's text format
      #
      # See the Qt::TextFormat enum for an explanation of the possible options.
      #
      # The default format is Qt::AutoText.
      def text_format
        _text_format
      end

      # @return [Qt::TextInteractionFlags]
      #
      # Specifies how the label should interact with user input if it displays
      # text.
      #
      # If the flags contain Qt::LinksAccessibleByKeyboard the focus policy is
      # also automatically set to Qt::StrongFocus. If
      # Qt::TextSelectableByKeyboard is set then the focus policy is set to
      # Qt::ClickFocus.
      #
      # The default value is Qt::LinksAccessibleByMouse.
      def text_interaction_flags
        _text_interaction_flags
      end

      # @return [Boolean]
      #
      # This property holds whether there is any text selected.
      #
      # hasSelectedText() returns true if some or all of the text has been
      # selected by the user; otherwise returns false.
      #
      # By default, this property is false.
      #
      # Note: The textInteractionFlags set on the label need to include either
      # TextSelectableByMouse or TextSelectableByKeyboard.
      def has_selected_text?
        _has_selected_text?
      end

      # @return [Boolean]
      #
      # This property holds whether the label will scale its contents to fill
      # all available space.
      #
      # When enabled and the label shows a pixmap, it will scale the pixmap
      # to fill the available space.
      #
      # This property's default is false.
      def has_scaled_contents?
        _has_scaled_contents?
      end

      # @return [Boolean]
      #
      # Specifies whether QLabel should automatically open links using
      # QDesktopServices::openUrl() instead of emitting the linkActivated()
      # signal.
      #
      # Note: The textInteractionFlags set on the label need to include
      # either LinksAccessibleByMouse or LinksAccessibleByKeyboard.
      #
      # The default value is false.
      def open_external_links?
        _open_external_links?
      end

      # @return [Boolean]
      #
      # This property holds the label's word-wrapping policy.
      #
      # If this property is true then label text is wrapped where necessary
      # at word-breaks; otherwise it is not wrapped at all.
      #
      # By default, word wrap is disabled.
      def word_wrap?
        _word_wrap?
      end

      # @param alignment [Qt::Alignment]
      # @return [nil]
      #
      # Sets the label's alignment property.
      def set_alignment(alignment)
        _set_alignment(alignment)
      end

      # @param buddy [QWidget]
      # @return [nil]
      #
      # Sets this label's buddy to buddy.
      #
      # When the user presses the shortcut key indicated by this label, the
      # keyboard focus is transferred to the label's buddy widget.
      #
      # The buddy mechanism is only available for QLabels that contain text
      # in which one character is prefixed with an ampersand, '&'. This
      # character is set as the shortcut key. See the
      # QKeySequence::mnemonic() documentation for details (to display an
      # actual ampersand, use '&&').
      #
      # In a dialog, you might create two data entry widgets and a label for
      # each, and set up the geometry layout so each label is just to the
      # left of its data entry widget (its "buddy"), for example:
      #
      #   QLineEdit *nameEdit  = new QLineEdit(this);
      #   QLabel    *nameLabel = new QLabel("&Name:", this);
      #   nameLabel->setBuddy(nameEdit);
      #   QLineEdit *phoneEdit  = new QLineEdit(this);
      #   QLabel    *phoneLabel = new QLabel("&Phone:", this);
      #   phoneLabel->setBuddy(phoneEdit);
      #   // (layout setup not shown)
      #
      # With the code above, the focus jumps to the Name field when the user
      # presses Alt+N, and to the Phone field when the user presses Alt+P.
      #
      # To unset a previously set buddy, call this function with buddy set to
      # nullptr.
      def set_buddy(buddy)
        _set_buddy(buddy)
      end

      # @param indent [Integer]
      # @return [nil]
      #
      # Sets the label's indent property.
      def set_indent(indent)
        _set_indent(indent)
      end

      # @param margin [Integer]
      # @return [nil]
      #
      # Sets the label's margin property.
      def set_margin(margin)
        _set_margin(margin)
      end

      # @param open [Boolean]
      # @return [nil]
      #
      # Sets the label's openExternalLinks property.
      def set_open_external_links(open)
        _set_open_external_links(open)
      end

      # @param movie [QMovie]
      # @return [nil]
      #
      # Sets the label contents to movie. Any previous content is cleared.
      # The label does NOT take ownership of the movie.
      #
      # The buddy shortcut, if any, is disabled.
      def set_movie(movie)
        _set_movie(movie)
      end

      # @param num [Integer, Float]
      # @return [nil]
      #
      # Sets the label contents to plain text containing the textual
      # representation of integer num. Any previous content is cleared. Does
      # nothing if the integer's string representation is the same as the
      # current contents of the label.
      #
      # The buddy shortcut, if any, is disabled.
      def set_num(num)
        _set_num(num)
      end

      # @param picture [QPicture]
      # @return [nil]
      #
      # Sets the label contents to picture. Any previous content is cleared.
      #
      # The buddy shortcut, if any, is disabled.
      def set_picture(picture)
        _set_picture(picture)
      end

      # @param pixmap [QPixmap]
      # @return [nil]
      #
      # Sets the label's pixmap property.
      def set_pixmap(pixmap)
        _set_pixmap(pixmap)
      end

      # @param provider [QTextDocument::ResourceProvider]
      # @return [nil]
      #
      # Sets the provider of resources for rich text of this label.
      #
      # Note: The label does not take ownership of the provider.
      def set_resource_provider(provider)
        _set_resource_provider(provider)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the label's scaledContents property.
      def set_scaled_contents(enabled)
        _set_scaled_contents(enabled)
      end

      # @param start [Integer]
      # @param length [Integer]
      # @return [nil]
      #
      # Selects text from position start and for length characters.
      #
      # Note: The textInteractionFlags set on the label need to include either
      # TextSelectableByMouse or TextSelectableByKeyboard.
      def set_selection(start, length)
        _set_selection(start, length)
      end

      # @param text [QString]
      # @return [nil]
      #
      # Sets the label's text property.
      def set_text(text)
        _set_text(QtCore::QString.new(text))
      end

      # @param format [Qt::TextFormat]
      # @return [nil]
      #
      # Sets the label's textFormat property.
      def set_text_format(format)
        _set_text_format(format)
      end

      # @param flags [Qt::TextInteractionFlags]
      # @return [nil]
      #
      # Sets the label's textInteractionFlags property.
      def set_text_interaction_flags(flags)
        _set_text_interaction_flags(flags)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the label's wordWrap property.
      def set_word_wrap(enabled)
        _set_word_wrap(enabled)
      end

      # @return [nil]
      #
      # Clears any label contents.
      def clear
        _clear
      end
    end
  end
end
