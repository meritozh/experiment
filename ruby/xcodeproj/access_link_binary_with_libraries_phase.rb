require 'xcodeproj'
require 'rainbow'

# 1, modify Link Binary With Libraries phase
project = Xcodeproj::Project.open('Pods/Pods.xcodeproj')

targets = project.targets

targets.each do |target|
  puts Rainbow("current in target: #{target.name}").orange
  link_phases = target.build_phases.select do |phase|
    phase.kind_of? Xcodeproj::Project::Object::PBXFrameworksBuildPhase
  end
  # Use link_phases.first is enough. One target can only have one link phase
  link_phases.first.files_references.each do |file_ref|
    ref_paths = file_ref.path
  end unless link_phases.empty?
  # Test, print all linked file (.framework/.tbd)
  # puts link_phases.first.file_display_names unless link_phases.empty?
end