# frozen_string_literal: true

class PreviewWindow < RubyQt6::Bando::QWidget
  def initialize(parent = nil)
    super(parent)

    @text_edit = QTextEdit.new ''
    @text_edit.set_read_only true
    @text_edit.set_line_wrap_mode QTextEdit::NoWrap

    @close_button = QPushButton.new(tr('&Close'))
    @close_button.clicked.connect(self, :close)

    layout = QVBoxLayout.new
    layout.add_widget(@text_edit)
    layout.add_widget(@close_button)

    set_layout(layout)
    set_window_title(tr('Preview'))
  end

  def set_window_flags(flags)
    super(flags)

    type = (flags & Qt::WindowType_Mask)
    if type == Qt::Window
      text = 'Qt::Window'
    elsif type == Qt::Dialog
      text = 'Qt::Dialog'
    elsif type == Qt::Sheet
      text = 'Qt::Sheet'
    elsif type == Qt::Drawer
      text = 'Qt::Drawer'
    elsif type == Qt::Popup
      text = 'Qt::Popup'
    elsif type == Qt::Tool
      text = 'Qt::Tool'
    elsif type == Qt::ToolTip
      text = 'Qt::ToolTip'
    elsif type == Qt::SplashScreen
      text = 'Qt::SplashScreen'
    end

    text += "\n| Qt::MSWindowsFixedSizeDialogHint" if (flags & Qt::MSWindowsFixedSizeDialogHint) != 0
    text += "\n| Qt::X11BypassWindowManagerHint" if (flags & Qt::X11BypassWindowManagerHint) != 0
    text += "\n| Qt::FramelessWindowHint" if (flags & Qt::FramelessWindowHint) != 0
    text += "\n| Qt::WindowTitleHint" if (flags & Qt::WindowTitleHint) != 0
    text += "\n| Qt::WindowSystemMenuHint" if (flags & Qt::WindowSystemMenuHint) != 0
    text += "\n| Qt::WindowMinimizeButtonHint" if (flags & Qt::WindowMinimizeButtonHint) != 0
    text += "\n| Qt::WindowMaximizeButtonHint" if (flags & Qt::WindowMaximizeButtonHint) != 0
    text += "\n| Qt::WindowContextHelpButtonHint" if (flags & Qt::WindowContextHelpButtonHint) != 0
    text += "\n| Qt::WindowShadeButtonHint" if (flags & Qt::WindowShadeButtonHint) != 0
    text += "\n| Qt::WindowStaysOnTopHint" if (flags & Qt::WindowStaysOnTopHint) != 0

    @text_edit.set_plain_text text
  end
end
