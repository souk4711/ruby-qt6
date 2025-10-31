RSpec.describe "RubyQt6::QtCore::QFlags" do
  it "#~" do
    expect(~RubyQt6::QtCore::Qt::AlignLeft).to be_a(RubyQt6::QtCore::Qt::Alignment)
    expect(~RubyQt6::QtCore::Qt::AlignLeft).to eq(~0x0001)
  end

  it "#&" do
    expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
    expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignCenter).to eq(0x0004)
    expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignLeft).to eq(0)
  end

  it "#^" do
    expect(RubyQt6::QtCore::Qt::AlignHCenter ^ RubyQt6::QtCore::Qt::AlignCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
  end

  it "#|" do
    expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
    expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignCenter).to eq(0x0084)
    expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignLeft).to eq(0x0005)
  end
end
