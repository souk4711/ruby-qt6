# frozen_string_literal: true

class PermissionsTab < RubyQt6::Bando::QWidget
  def initialize(fileinfo, parent = nil)
    super(parent)

    permissions_group = QGroupBox.new(tr('Permissions'))

    readable = QCheckBox.new(tr('Readable'))
    readable.set_checked true if fileinfo.readable?

    writable = QCheckBox.new(tr('Writable'))
    writable.set_checked true if fileinfo.writable?

    executable = QCheckBox.new(tr('Executable'))
    executable.set_checked true if fileinfo.executable?

    owner_group = QGroupBox.new(tr('Ownership'))

    owner_label = QLabel.new(tr('Owner'))
    owner_value_label = QLabel.new(fileinfo.owner)
    owner_value_label.set_frame_style QFrame::Panel.to_i | QFrame::Sunken.to_i

    group_label = QLabel.new(tr('Group'))
    group_value_label = QLabel.new(fileinfo.group)
    group_value_label.set_frame_style QFrame::Panel.to_i | QFrame::Sunken.to_i

    p = QVBoxLayout.new
    p.add_widget(readable)
    p.add_widget(writable)
    p.add_widget(executable)
    permissions_group.set_layout(p)

    o = QVBoxLayout.new
    o.add_widget(owner_label)
    o.add_widget(owner_value_label)
    o.add_widget(group_label)
    o.add_widget(group_value_label)
    owner_group.set_layout(o)

    m = QVBoxLayout.new
    m.add_widget(permissions_group)
    m.add_widget(owner_group)
    m.add_stretch(1)
    set_layout(m)
  end
end
