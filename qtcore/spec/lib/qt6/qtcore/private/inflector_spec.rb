RSpec.describe RubyQt6::QtCore::Private::Inflector do
  let(:inflector) { described_class.new }

  it "#camelize" do
    expect(inflector.camelize("about_to_quit")).to eq("aboutToQuit")
    expect(inflector.camelize("application_name_changed")).to eq("applicationNameChanged")
    expect(inflector.camelize("destroyed")).to eq("destroyed")
  end

  it "#underscore" do
    expect(inflector.underscore("aboutToQuit")).to eq("about_to_quit")
    expect(inflector.underscore("applicationNameChanged")).to eq("application_name_changed")
    expect(inflector.underscore("destroyed")).to eq("destroyed")
  end

  it "#constantize" do
    expect(inflector.constantize("QObject")).to eq(QObject)
    expect(inflector.constantize("RubyQt6::QtCore::QObject")).to eq(QObject)
  end
end
