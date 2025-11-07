# frozen_string_literal: true

class Window < RubyQt6::Bando::QWidget
  q_object do
    slot 'browse()'
    slot 'find()'
  end

  def initialize(parent = nil)
    super(parent)

    @browse_button = create_button(tr('&Browse...'), :browse)
    @find_button = create_button(tr('&Find'), :find)
    @quit_button = create_button(tr('&Quit'), :close)

    @file_combobox = create_combobox(tr('*'))
    @text_combobox = create_combobox
    @directory_combobox = create_combobox(QDir.current_path)

    @file_label = QLabel.new(tr('Named:'))
    @text_label = QLabel.new(tr('Containing text:'))
    @directory_label = QLabel.new(tr('In directory:'))
    @files_found_label = QLabel.new

    create_files_table

    buttons_layout = QHBoxLayout.new
    buttons_layout.add_stretch
    buttons_layout.add_widget(@find_button)
    buttons_layout.add_widget(@quit_button)

    main_layout = QGridLayout.new
    main_layout.add_widget(@file_label, 0, 0)
    main_layout.add_widget(@file_combobox, 0, 1, 1, 2)
    main_layout.add_widget(@text_label, 1, 0)
    main_layout.add_widget(@text_combobox, 1, 1, 1, 2)
    main_layout.add_widget(@directory_label, 2, 0)
    main_layout.add_widget(@directory_combobox, 2, 1)
    main_layout.add_widget(@browse_button, 2, 2)
    main_layout.add_widget(@files_table, 3, 0, 1, 3)
    main_layout.add_widget(@files_found_label, 4, 0)
    main_layout.add_layout(buttons_layout, 5, 0, 1, 3)
    set_layout(main_layout)

    set_window_title(tr('Find Files'))
    resize(700, 300)
  end

  def browse
    directory = QFileDialog.get_existing_directory(self, tr('Find Files'), QDir.current_path)
    @directory_combobox.add_item(directory)
    @directory_combobox.set_current_index @directory_combobox.current_index + 1
  end

  def find
    @files_table.set_row_count 0

    filename = @file_combobox.current_text
    text = @text_combobox.current_text
    path = @directory_combobox.current_text

    directory = QDir.new(path)
    filename = '*' if filename.empty?
    files = directory.entry_list(QStringList.new << filename, QDir::Files | QDir::NoSymLinks)

    files = find_files(directory, files, text) unless text.empty?
    show_files(directory, files)
  end

  def find_files(directory, files, text)
    progress_dialog = QProgressDialog.new('', tr('&Cancel'), 0, files.length, self)
    progress_dialog.set_window_title tr('Find Files')

    found_files = QStringList.new
    (0...files.length).each do |i|
      progress_dialog.set_value i
      progress_dialog.set_label_text tr(format('Searching file number %s of %s...', i, files.length))
      QApplication.process_events
      break if progress_dialog.was_canceled

      file = QFile.new(directory.absolute_file_path(files[i]))
      next unless file.open(QFile::ReadOnly.to_qflags)

      inf = QTextStream.new(file)
      until inf.at_end
        break if progress_dialog.was_canceled

        line = inf.read_line
        if line.contains(text)
          found_files << files[i]
          break
        end
      end
    end

    progress_dialog.delete_later
    found_files
  end

  def show_files(directory, files)
    (0...files.length).each do |i|
      file = QFile.new(directory.absolute_file_path(files[i]))
      size = QFileInfo.new(file).size

      filename_item = QTableWidgetItem.new(files[i])
      filename_item.set_flags Qt::ItemIsEnabled
      size_item = QTableWidgetItem.new(format('%d KB', (size + 1023) / 1024))
      size_item.set_text_alignment Qt::AlignVCenter | Qt::AlignRight
      size_item.set_flags Qt::ItemIsEnabled

      row = @files_table.row_count
      @files_table.insert_row(row)
      @files_table.set_item(row, 0, filename_item)
      @files_table.set_item(row, 1, size_item)
    end
    @files_found_label.set_text tr('%d file(s) found' % files.length)
  end

  def create_button(text, member)
    button = QPushButton.new(text)
    button.clicked.connect(self, member)
    button
  end

  def create_combobox(text = '')
    combobox = QComboBox.new
    combobox.set_editable true
    combobox.add_item(text)
    combobox.set_size_policy(QSizePolicy::Expanding, QSizePolicy::Preferred)
    combobox
  end

  def create_files_table
    @files_table = QTableWidget.new(0, 2)
    @files_table.set_horizontal_header_labels QStringList.new << tr('File Name') << tr('Size')
    @files_table.horizontal_header.set_section_resize_mode(0, QHeaderView::Stretch)
    @files_table.vertical_header.hide
    @files_table.set_show_grid false
  end
end
