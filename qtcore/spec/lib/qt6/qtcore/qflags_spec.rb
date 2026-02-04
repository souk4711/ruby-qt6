RSpec.describe "QFlags" do
  it "#~" do
    expect(~Qt::AlignLeft).to be_a(Qt::Alignment)
    expect(~Qt::AlignLeft).to eq(~0x0001)
  end

  it "#&" do
    expect(Qt::AlignHCenter & Qt::AlignCenter).to be_a(Qt::Alignment)
    expect(Qt::AlignHCenter & Qt::AlignCenter).to eq(0x0004)
    expect(Qt::AlignHCenter & Qt::AlignLeft).to eq(0)
  end

  it "#^" do
    expect(Qt::AlignHCenter ^ Qt::AlignCenter).to be_a(Qt::Alignment)
  end

  it "#|" do
    expect(Qt::AlignHCenter | Qt::AlignCenter).to be_a(Qt::Alignment)
    expect(Qt::AlignHCenter | Qt::AlignCenter).to eq(0x0084)
    expect(Qt::AlignHCenter | Qt::AlignLeft).to eq(0x0005)
  end
end
