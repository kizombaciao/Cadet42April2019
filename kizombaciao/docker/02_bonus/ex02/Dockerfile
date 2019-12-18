FROM python:3.6.5-slim

# Set the working directory to /app
WORKDIR /app

# Copy current directory contents into the container at /app
COPY . /app

# Install libraries
RUN pip --no-cache-dir install numpy pandas seaborn sklearn jupyter

# Make port 8888 available to the world outside this container
EXPOSE 8888

# Run jupyter when container launches
CMD ["jupyter", "notebook", "--ip='*'", "--port=8888", "--no-browser", "--allow-root"]

