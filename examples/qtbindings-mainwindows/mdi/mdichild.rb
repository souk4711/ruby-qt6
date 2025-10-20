# frozen_string_literal: true

class MdiChild < RubyQt6::Bando::QTextEdit
  attr_reader :current_file

  q_object do
    slot 'document_was_modified()'
  end

  def initialize
    super
    @is_untitled = true
  end

  def new_file
    @@sequence_number = 1
    @is_untitled = true
    @current_file = tr(format('document%s.txt', @@sequence_number += 1))
    set_window_title("#{@current_file}[*]")
    document.contents_changed.connect(self, :document_was_modified)
  end

  def load_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::ReadOnly | QFile::Text)
      QMessageBox.warning(self, tr('MDI'), tr(format("Cannot read file %s:\n%s.", file_name, file.errorString)))
      return false
    end

    inf = QTextStream.new(file)
    QApplication.set_override_cursor QCursor.new(Qt::WaitCursor)
    set_plain_text(inf.read_all)
    QApplication.restore_override_cursor

    set_current_file(file_name)
    document.contents_changed.connect(self, :document_was_modified)
    true
  end

  def save
    return save_as if @is_untitled

    save_file(@current_file)
  end

  def save_as
    file_name = QFileDialog.get_save_file_name(self, tr('Save As'), @current_file)
    return false if (!file_name) || file_name.empty?

    save_file(file_name)
  end

  def save_file(file_name)
    file = QFile.new(file_name)
    unless file.open(QFile::WriteOnly | QFile::Text)
      QMessageBox.warning(self, tr('MDI'), tr(format("Cannot write file %s:\n%s.", file_name, file.error_string)))
      return false
    end

    outf = QTextStream.new(file)
    QApplication.set_override_cursor QCursor.new(Qt::WaitCursor)
    outf << to_plain_text
    QApplication.restore_override_cursor

    set_current_file(file_name)
    true
  end

  def user_friendly_current_file
    stripped_name(@current_file)
  end

  def close_event(event)
    if maybe_save
      event.accept
    else
      event.ignore
    end
  end

  def document_was_modified
    set_window_modified(document.modified?)
  end

  def maybe_save
    if document.modified?
      ret = QMessageBox.warning(
        self,
        tr('MDI'),
        tr("'%s' has been modified.\n Do you want to save your changes?" % user_friendly_current_file),
        QMessageBox::Yes | QMessageBox::Default,
        QMessageBox::No,
        QMessageBox::Cancel | QMessageBox::Escape
      )
      if ret == QMessageBox::Yes
        return save
      elsif ret == QMessageBox::Cancel
        return false
      end
    end
    true
  end

  def set_current_file(file_name)
    @current_file = QFileInfo.new(file_name).canonical_file_path
    @is_untitled = false

    document.set_modified(false)
    set_window_modified(false)
    set_window_title("#{user_friendly_current_file}[*]")
  end

  def stripped_name(full_file_name)
    QFileInfo.new(full_file_name).file_name
  end
end
