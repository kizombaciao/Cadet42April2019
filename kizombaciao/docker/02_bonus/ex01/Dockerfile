FROM continuumio/miniconda3

# Set the working directory to /app
WORKDIR /app

# Install libraries
RUN conda install jupyter -y && \
    conda install pandas -y && \
    conda clean -y -all

# Make port 8888 available to the world outside this container
EXPOSE 8888

# Create mountpoint
VOLUME /app

# Run jupyter when container launches
CMD ["jupyter", "notebook", "--ip='*'", "--port=8888", "--no-browser", "--allow-root"]


