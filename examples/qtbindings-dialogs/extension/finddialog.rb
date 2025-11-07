# frozen_string_literal: true

class FindDialog < RubyQt6::Bando::QDialog
  def initialize(parent = nil)
    super(parent)

    @label = QLabel.new(tr('Find &what:'))
    @line_edit = QLineEdit.new
    @label.set_buddy @line_edit

    @case_checkbox = QCheckBox.new(tr('Match &case'))
    @fromstart_checkbox = QCheckBox.new(tr('Search from &start'))
    @fromstart_checkbox.set_checked true

    @find_button = QPushButton.new(tr('&Find'))
    @find_button.set_default true

    @close_button = QPushButton.new(tr('Close'))

    @more_button = QPushButton.new(tr('&More'))
    @more_button.set_checkable true
    @more_button.set_auto_default false

    @extension = QWidget.new

    @wholewords_checkbox = QCheckBox.new(tr('&Whole words'))
    @backward_checkbox = QCheckBox.new(tr('Search &backward'))
    @searchselection_checkbox = QCheckBox.new(tr('Search se&lection'))

    @close_button.clicked.connect(self, :close)
    @more_button.toggled.connect(@extension, :setVisible)

    @extension_layout = QVBoxLayout.new
    @extension_layout.set_contents_margins QMargins.new
    @extension_layout.add_widget(@wholewords_checkbox)
    @extension_layout.add_widget(@backward_checkbox)
    @extension_layout.add_widget(@searchselection_checkbox)
    @extension.set_layout @extension_layout

    topleft_layout = QHBoxLayout.new
    topleft_layout.add_widget(@label)
    topleft_layout.add_widget(@line_edit)

    left_layout = QVBoxLayout.new
    left_layout.add_layout(topleft_layout)
    left_layout.add_widget(@case_checkbox)
    left_layout.add_widget(@fromstart_checkbox)
    left_layout.add_stretch(1)

    right_layout = QVBoxLayout.new
    right_layout.add_widget(@find_button)
    right_layout.add_widget(@close_button)
    right_layout.add_widget(@more_button)
    right_layout.add_stretch(1)

    main_layout = QGridLayout.new
    main_layout.set_size_constraint QLayout::SetFixedSize
    main_layout.add_layout(left_layout, 0, 0)
    main_layout.add_layout(right_layout, 0, 1)
    main_layout.add_widget(@extension, 1, 0, 1, 2)
    set_layout(main_layout)

    set_window_title(tr('Extension'))
    @extension.hide
  end
end
