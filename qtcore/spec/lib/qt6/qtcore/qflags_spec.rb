RSpec.describe "RubyQt6::QtCore::QFlags" do
  it "#&" do
    expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignCenter).to eq(0x0004)
    expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignLeft).to eq(0)
  end

  it "#^" do
  end

  it "#|" do
    expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignCenter).to eq(0x0084)
    expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignLeft).to eq(0x0005)
  end

  it "#~" do
    expect(~RubyQt6::QtCore::Qt::AlignLeft).to eq(~0x0001)
  end

  it "#zero?" do
    expect(RubyQt6::QtCore::Qt::Alignment.new).to be_zero
    expect(RubyQt6::QtCore::Qt::Alignment.from_int(1)).not_to be_zero
  end

  it "#nonzero?" do
    expect(RubyQt6::QtCore::Qt::Alignment.new).not_to be_nonzero
    expect(RubyQt6::QtCore::Qt::Alignment.from_int(1)).to be_nonzero
  end
end
