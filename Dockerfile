# Base image with Ruby
FROM ruby:3.1

# Install additional languages
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        curl \
        git \
        golang \
        perl
RUN gem install bundler

COPY --from=besutkode/gotty /go/src/github.com/yudai/gotty/gotty /gotty

# Working directory for your application
WORKDIR /app

# Copy your application code (including server.sh)
COPY . .
RUN bundle install

# Grant execute permissions to server.sh
RUN chmod +x server.sh

# Define the default command to run the service
# CMD ["/bin/bash", "-c", "./server.sh"]
CMD ["/gotty", "-w", "--title-format", "Tactile DS", "ruby", "terminal-menu.rb"]
