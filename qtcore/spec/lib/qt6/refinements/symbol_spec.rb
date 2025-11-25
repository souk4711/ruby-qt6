RSpec.describe Symbol do
  it "#o_qstr" do
    o = :abc.to_qstr
    expect(o).to be_a(RubyQt6::QtCore::QString)
    expect(o).to eq("abc")
  end
end
