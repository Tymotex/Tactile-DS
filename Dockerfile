FROM ruby:3.1

# Install necessary languages and dependencies.
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        curl \
        git \
        golang \
        perl

# Later, `bundle install` is executed to install Gemfile dependencies.
RUN gem install bundler

# GoTTy is necessary for hosting a CLI command with a web frontend.
COPY --from=besutkode/gotty /go/src/github.com/yudai/gotty/gotty /gotty

WORKDIR /app

# Copy your application code (including server.sh)
COPY . .

# Install Gemfile dependencies.
RUN bundle install

# Produce the actual C binaries that get run for the data structure visualisers.
RUN ./util/scripts/make_recurse.sh

# Grant execute permissions to server.sh
RUN chmod +x server.sh

# Define the default command to run the service
CMD ["/gotty", "-w", "--title-format", "Tactile DS", "ruby", "terminal-menu.rb"]
